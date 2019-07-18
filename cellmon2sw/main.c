#include <msp430.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "utilityfn.h"
#include "ad7280a.h"
#include "usci.h"

#define RS485_OURID 1
#define OPCODE_READVOLTAGES 1
#define OPCODE_RESET        2

char * heap_buf;
char txbuf[64];

uint16_t cell_voltages[6];

void hwuart_sendstr(char * ptr) {
	P3OUT |= BIT2 | BIT3;
	while (*ptr != '\0') {
		UCA0TXBUF = *ptr++;
		while(!(IFG2 & UCA0TXIFG)) { __nop(); }
	}
	while (UCA0STAT & UCBUSY) {};
	P3OUT &= ~(BIT2 | BIT3);
}

void timer_setup() {
	//TA1CTL = ID_3 | TASSEL_2 | MC_1 | TACLR;
	
	// 1 cycle @ 16MHz = 0.0625uS, tick once per mS: 1000.0/(0.0625*8.0) = 2000
	//TA1CCR0 = (2000 - 1);
	
	// 1 cycle @ 8MHz = 0.125uS, tick once per mS: 1000.0/(0.125*8.0) = 1000
	//TA1CCR0 = (1000 - 1);
	
	// 1 cycle @ 1MHz = 1uS, tick once every 250 mS: 250.0/(1.0 * 1.0) = 250
	//TA1CCR0 = (250 - 1);
	
	//TA1CCTL0 = CCIE;
}

void usci_a0b0_setup() {
	// UCA0
	UCA0CTL1 |= UCSSEL_2 | UCSWRST;

	// 9600 at 1MHz
	UCA0BR0 = 104;
	UCA0BR1 = 0;
	UCA0MCTL |= UCBRF_1;
	// 9600 at 8MHz
	//UCA0BR0 = 64;
	//UCA0BR1 = 3;
	//UCA0MCTL = UCBRS_2;
	// 9600 at 16MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL |= UCBRF_3 | UCOS16;

	UCA0CTL1 &= ~(UCSWRST);
	//IE2 |= UCA0RXIE;
	// UCB0
	/*
	UCB0CTL1 |= UCSSEL_2 | UCSWRST;
	UCB0CTL0 = UCMST | UCMODE_0 | UCCKPL | UCMSB | UCSYNC;
	UCB0BR0 = 96;
	UCB0BR1 = 0;
	UCB0CTL1 &= ~(UCSWRST);
	*/
}

void gpio_setup() {
	// UCA0 / RS485UART
	// UCB0 / SPI
	//P1SEL |= BIT1 | BIT2 | BIT5 | BIT6 | BIT7;
	//P1SEL2 |= BIT1 | BIT2 | BIT5 | BIT6 | BIT7;
	
	// UCA0 = Hardware UART
	// Software SPI mode
	P1SEL |= BIT1 | BIT2;
	P1SEL2 |= BIT1 | BIT2;
	P1DIR |= BIT5 | BIT7;

	// P3.2 - RS485TXEN
	// P3.3 - /RS485RXEN
	// P3.5 - /AD_CNVST
	// P3.6 - /AD_CS
	// P3.7 - /AD_PD
	//P3OUT = BIT5 | BIT6 | BIT7;
	P3OUT = BIT5 | BIT6;
	P3DIR = 0xff;
}

unsigned int i;

//void clock_enablexternalosc() {
//	__bic_SR_register(OSCOFF);
//	BCSCTL1 |= XTS;
//	//BCSCTL3 = LFXT1S0;
//	//BCSCTL3 = XT2S2;
//check_clear_1:
//	IFG1 &= ~OFIFG;
//	i = 0xff;
//	while (i--) { __nop(); }
//	if (IFG1 & OFIFG) {
//		goto check_clear_1;
//	}
//	//BCSCTL2 = SELM0 | SELM1;
//	
//}

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

	//BCSCTL1 = CALBC1_16MHZ;
	//DCOCTL = CALDCO_16MHZ;
	
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	
	gpio_setup();
	usci_a0b0_setup();

//	P2OUT |= BIT2 | BIT3;
//	P3DIR |= BIT2 | BIT3;

//	P1SEL |= BIT1 | BIT2;
//	P1SEL2 |= BIT1 | BIT2;
//	UCA0CTL1 |= UCSSEL_2 | UCSWRST;
	// 9600 @ 1MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL = UCBRS_1;
	// 9600 @ 16MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL = UCBRF_3 | UCOS16;
	// 9600 @ 8MHz
//	UCA0BR0 = 52;
//	UCA0BR1 = 0;
//	UCA0MCTL = UCBRF_3 | UCOS16;

	//UCA0MCTL = (3 << 4) | UCOS16; // 3 << 4 = UCBRFx
//	UCA0CTL1 &= ~UCSWRST;

//	IFG2 &= ~UCA0RXIFG;
//	IE2 |= UCA0RXIE;
	
//	while (i --) { __nop(); __nop(); }

//	clock_enablexternalosc();

//	UCA0CTL1 |= UCSSEL_2 | UCSWRST;
//	UCA0BR0 = 104;
//	UCA0BR1 = 0;
//	UCA0CTL1 &= ~UCSWRST;

	while (i --) { __nop(); __nop(); }
	while (i --) { __nop(); __nop(); }
	
	//ad7280a_write(1, 0xf3, 0xa, 2);

	heap_buf = txbuf;
	packet_receive();

	__asm("\tnop\n");
	__eint();
	// __bis_SR_register(GIE);

	while (1) {
		if (packet_ctx.state == PACKET_STATE_RECEIVE_SUCCESS) {
			// Got a packet... decode and respond.
			if (packet_ctx.buf_start[0] == RS485_OURID &&
					packet_ctx.buf_start[2] == OPCODE_READVOLTAGES) {
				uint8_t src;
				src = packet_ctx.buf_start[1];
				AD_PORT |= (AD_PD | AD_CNVST);
				//Utility_delay(0x800);
				Utility_delay(0x200);
				AD_PORT &= ~(AD_CS);
				ad7280a_rw((uint8_t *)heap_buf, 0, 0x1c, 0x0, 1);
				ad7280a_rw((uint8_t *)heap_buf, 0, 0xd, 0xa0, 1);
				ad7280a_rw((uint8_t *)heap_buf, 0, 0x1d, 0x2, 1);
				AD_PORT &= ~AD_CNVST;
				Utility_delay(0x1);
				AD_PORT |= AD_CNVST;
				heap_buf[0] = src;
				heap_buf[1] = RS485_OURID;
				heap_buf[2] = OPCODE_READVOLTAGES;
				heap_buf[3] = 0;
				//Utility_delay(0x80);
				uint8_t * ptr = ((uint8_t *)heap_buf) + 4;
				uint16_t * ptr2 = (uint16_t *)(((uint8_t *)heap_buf) + 4);
				for (i = 0; i < 6; i++) {
					ad7280a_rw(ptr, 0x1f, 0, 0, 0);
					*ptr2 = ad7280a_decodevoltage(ptr);
					ptr2++;
					ptr += 4;
				}
				AD_PORT |= AD_CS;
				AD_PORT &= ~(AD_PD | AD_CNVST);
				P3OUT |= BIT2 | BIT3;
				packet_send(4 + (6 * 2));
			}
			//IFG2 &= ~(UCA0RXIFG);
		} else
		if (packet_ctx.state == PACKET_STATE_SEND_SUCCESS) {
			if (!(UCA0STAT & UCBUSY)) {
				P3OUT &= ~(BIT2 | BIT3);
				packet_receive();
			}
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

