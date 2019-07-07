#include <stdint.h>
#include "crcfn.h"

#define WIDTH  (8 * sizeof(uint8_t))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0x2f

uint8_t CRC_calculate(uint8_t const message[], int count) {
	uint8_t remainder = 0;
	int byte;
	uint8_t bit;
	
	count = count - 1;
	for (byte = 0; byte < count; ++byte) {
		remainder ^= (message[byte] << (WIDTH - 8));
		for (bit = 8; bit > 0; --bit) {
			if (remainder & TOPBIT) {
				remainder = (remainder << 1) ^ POLYNOMIAL;
			} else {
				remainder = (remainder << 1);
			}
		}
	}
	return remainder ^ message[count];
}

