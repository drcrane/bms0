#include <msp430.h>

#define SPIPORTDIR  P1DIR
#define SPIPORTOUT  P1OUT
#define SCLKBIT     BIT5
#define MOSIBIT     BIT6
#define SPIPORTIN   P1IN
#define MISOBIT     BIT7

void SPI_init() {
	SPIPORTDIR &= ~MISOBIT;
	SPIPORTDIR |= (MOSIBIT | SCLKBIT);
	SPIPORTOUT &= ~(MOSIBIT | SCLKBIT);
}

/*
int SPI_rw(int v_out) {
	int count;
	int v_in = 0;
	SPIPORTOUT |= SCLKBIT;
	for (count = 8; count != 0; count--) {
		__nop();
		__nop();
		v_in <<= 1;
		if (SPIPORTIN & MISOBIT) {
			v_in |= 0x01;
		}
		if (v_out & 0x80) {
			SPIPORTOUT |= MOSIBIT;
		} else {
			SPIPORTOUT &= ~MOSIBIT;
		}
		v_out <<= 1;
		SPIPORTOUT &= ~SCLKBIT;
		__nop();
		__nop();
		SPIPORTOUT |= SCLKBIT;
	}
	v_in <<= 1;
	if (SPIPORTIN & MISOBIT) {
		v_in |= 0x01;
	}
	return v_in;
}
*/

int SPI_rw(int v_out) {
	int count;
	int v_in = 0;
	for (count = 8; count != 0; count--) {
		// Rising Edge
		SPIPORTOUT |= SCLKBIT;
		if (v_out & 0x80) {
			SPIPORTOUT |= MOSIBIT;
		} else {
			SPIPORTOUT &= ~MOSIBIT;
		}
		v_out <<= 1;
		__nop();
		__nop();
		v_in <<= 1;
		if (SPIPORTIN & MISOBIT) {
			v_in |= 0x01;
		}
		SPIPORTOUT &= ~SCLKBIT;
		__nop();
		__nop();
	}
	return v_in;
}

