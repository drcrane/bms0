#include <msp430.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "utilityfn.h"
#include "ad7280a.h"

void hwuart_sendstr(char * ptr) {
	while (*ptr != '\0') {
		UCA0TXBUF = *ptr++;
		while(!(IFG2 & UCA0TXIFG)) { __nop(); }
	}
}

unsigned int i;

void clock_enablexternalosc() {
	__bic_SR_register(OSCOFF);
	BCSCTL1 |= XTS;
	//BCSCTL3 = LFXT1S0;
	BCSCTL3 = XT2S2;
check_clear_1:
	IFG1 &= ~OFIFG;
	i = 0xff;
	while (i--) { __nop(); }
	if (IFG1 & OFIFG) {
		goto check_clear_1;
	}
	//BCSCTL2 = SELM0 | SELM1;
	
}

unsigned int wdt_ctr;

int main() __attribute__ ((naked));
int main() {
	WDTCTL = WDTPW + WDTHOLD;

	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;

	P2OUT |= BIT2 | BIT3;
	P3DIR |= BIT2 | BIT3;

	P1SEL |= BIT1 | BIT2;
	P1SEL2 |= BIT1 | BIT2;
	UCA0CTL1 |= UCSSEL_2 | UCSWRST;
	// 9600 @ 1MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL = UCBRS_1;
	// 9600 @ 16MHz
	//UCA0BR0 = 104;
	//UCA0BR1 = 0;
	//UCA0MCTL = UCBRF_3 | UCOS16;
	// 9600 @ 8MHz
	UCA0BR0 = 52;
	UCA0BR1 = 0;
	UCA0MCTL = UCBRF_3 | UCOS16;

	//UCA0MCTL = (3 << 4) | UCOS16; // 3 << 4 = UCBRFx
	UCA0CTL1 &= ~UCSWRST;

//	IFG2 &= ~UCA0RXIFG;
//	IE2 |= UCA0RXIE;
	
	while (i --) { __nop(); __nop(); }

	clock_enablexternalosc();

	UCA0CTL1 |= UCSSEL_2 | UCSWRST;
	UCA0BR0 = 104;
	UCA0BR1 = 0;
	UCA0CTL1 &= ~UCSWRST;

	while (i --) { __nop(); __nop(); }
	while (i --) { __nop(); __nop(); }
	
	//ad7280a_write(1, 0xf3, 0xa, 2);

	while (1) {
		while (i --) { __nop(); __nop(); __nop(); __nop(); }
		hwuart_sendstr("TEST\n");
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

