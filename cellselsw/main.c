#include <msp430.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "utilityfn.h"
#include "usci.h"
#include "timerfn.h"
#include "relaysm.h"

#define RS485_OURID		0x10
#define OPCODE_READVOLTAGES	1
#define OPCODE_RESET		2
#define OPCODE_SETRELAYS	3
#define OPCODE_GETRELAYS	4
#define OPCODE_GETBUSVOLTAGES	5
#define OPCODE_GETSTATE         7

char * heap_buf;
char txbuf[64];

void hwuart_sendstr(char * ptr) {
	P3OUT |= BIT2 | BIT3;
	while (*ptr != '\0') {
		UCA0TXBUF = *ptr++;
		while(!(IFG2 & UCA0TXIFG)) { __nop(); }
	}
	while (UCA0STAT & UCBUSY) {};
	P3OUT &= ~(BIT2 | BIT3);
}

void usci_a0b0_setup() {
	// UCA0
	UCA0CTL1 |= UCSSEL_2 | UCSWRST;
	// 9600 at 8MHz
	//UCA0BR0 = 64;
	//UCA0BR1 = 3;
	//UCA0MCTL = UCBRS_2;
	// 9600 at 8MHz
	UCA0BR0 = 52;
	UCA0BR1 = 0;
	UCA0MCTL |= UCBRF_1 | UCOS16;
	// 9600 at 16MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL |= UCBRF_3 | UCOS16;
	UCA0CTL1 &= ~(UCSWRST);
	//IE2 |= UCA0RXIE;
	// UCB0 - I2C Mode
	UCB0CTL1 |= UCSSEL_2 | UCSWRST;
	UCB0CTL0 = UCMST | UCMODE_0 | UCCKPL | UCMSB | UCSYNC;
	UCB0BR0 = 96;
	UCB0BR1 = 0;
	UCB0CTL1 &= ~(UCSWRST);
}

void gpio_setup() {
	// UCA0 / RS485UART
	// UCB0 / I2C
	P1SEL |= BIT1 | BIT2 | BIT6 | BIT7;
	P1SEL2 |= BIT1 | BIT2 | BIT6 | BIT7;

	// P3.0 - SWGNDEN
	// P3.1 - SW5VEN
	// P3.7 - IOEXRST
	P3OUT = 0;
	P3DIR = 0xff;

	// P2.3 - DS18B20 (Input)
	// P2.4 - DISCH_BUSB
	// P2.5 - DISCH_BUSA
	P2OUT = 0;
	P2DIR = ~(BIT3);
	
	// P1.0 - RS485TXEN
	// P1.3 - /RS485RXEN
	// P1.4 - NC
	// P1.5 - NC
	P1OUT = 0;
	P1DIR = BIT0 | BIT3 | BIT4 | BIT5;
}

static void rs485_transmit() {
	P1OUT |= (BIT0 | BIT3);
}

static void rs485_receive() {
	P1OUT &= ~(BIT0 | BIT3);
}

// Should I move this to timerfn??
static void timer_setup() {
	// ID_3 = clock /8
	TA1CTL = ID_3 | TASSEL_2 | MC_1 | TACLR;
	
	// 1 cycle @ 16MHz = 0.0625uS, tick once per mS: 1000.0/(0.0625*8.0) = 2000
	//TA1CCR0 = (2000 - 1);
	
	// 1 cycle @ 8MHz = 0.125uS, tick once per mS: 1000.0/(0.125*8.0) = 1000
	TA1CCR0 = (1000 - 1);
	TA1CCTL0 = CCIE;	
}

unsigned int i;

int my_memcpy(char * dst, char * src, size_t size) {
	while (size--) {
		*dst = *src;
		dst++;
		src++;
	}
	return 0;
}

unsigned int wdt_ctr;

int main() __attribute__ ((naked));
int main() {
	WDTCTL = WDTPW | WDTHOLD;

	BCSCTL1 = CALBC1_8MHZ;
	DCOCTL = CALDCO_8MHZ;

	gpio_setup();
	usci_a0b0_setup();
	timer_initialise();
	timer_setup();
	i2c_initialise();

	while (i --) { __nop(); __nop(); }
	while (i --) { __nop(); __nop(); }
	
	heap_buf = txbuf;
	packet_receive();

	mcp23017_ctx.oper = 0;
	relay_ctx.state = 0;
	relay_ctx.current_cb = NULL;

	__asm("\tnop\n");
	__eint();
	// __bis_SR_register(GIE);

	while (1) {
		if (packet_ctx.state == PACKET_STATE_RECEIVE_SUCCESS) {
			// Got a packet... decode and respond.
			if (packet_ctx.buf_start[0] == RS485_OURID) {
				if (packet_ctx.buf_start[2] == OPCODE_READVOLTAGES) {
					rs485_transmit();
					heap_buf[0] = heap_buf[1];
					heap_buf[1] = RS485_OURID;
					heap_buf[2] = 0;
					heap_buf[3] = 0;
					packet_send(4);
				} else
				if (packet_ctx.buf_start[2] == OPCODE_SETRELAYS) {
					relay_ctx.state = 0;
					relay_initialise();
					relay_fusedcheck_process();
					packet_receive();
				} else
				if (packet_ctx.buf_start[2] == OPCODE_GETRELAYS) {
				} else
				if (packet_ctx.buf_start[2] == OPCODE_GETSTATE) {
					rs485_transmit();
					heap_buf[0] = heap_buf[1];
					heap_buf[1] = RS485_OURID;
					heap_buf[2] = 0;
					heap_buf[3] = 0;
					heap_buf[4] = relay_ctx.state;
					heap_buf[5] = 0;
					heap_buf[6] = 0;
					heap_buf[7] = 0;
					packet_send(8);
				}
			}
		} else
		if (packet_ctx.state == PACKET_STATE_SEND_SUCCESS) {
			if (!(UCA0STAT & UCBUSY)) {
				rs485_receive();
				packet_receive();
			}
		} else
		if (mcp23017_ctx.oper == MCP23017_OPER_COMPLETE) {
			if (mcp23017_ctx.callback != NULL) {
				mcp23017_ctx.callback(mcp23017_ctx.oper);
			} else {
				mcp23017_ctx.oper = MCP23017_OPER_IDLE;
			}
		} else
		if (relay_ctx.current_cb != NULL) {
			relay_ctx.current_cb();
		} else {
			timer_docallbacks();
		}
	}

	while(1) { __nop(); };
}

void Watchdog_ISR() __attribute__((interrupt(WDT_VECTOR)));
void Watchdog_ISR() {
	wdt_ctr ++;
	if (wdt_ctr == 0) {
		WDTCTL = 0x0a0a;
	}
}

