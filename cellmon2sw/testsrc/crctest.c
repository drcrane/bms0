#include <stdio.h>
#include <stdint.h>

#include "../crcfn.h"
#include "../crcfn.c"

uint16_t ad7280a_decodevoltage(uint8_t * ptr) {
	uint16_t voltage;
	uint8_t sentcrc, calccrc;
	uint8_t buf[4];
	sentcrc = ((ptr[0] & 0xff) >> 2) | ((ptr[1] & 0x3) << 6);
	buf[2] = (ptr[1] & 0xff) >> 2;
	buf[2] |= (ptr[2] & 0x3) << 6;
	buf[1] = (ptr[2] & 0xff) >> 2;
	buf[1] |= (ptr[3] & 0x3) << 6;
	buf[0] = (ptr[3] & 0xff) >> 2;
	calccrc = CRC_calculate(buf, 3);
	voltage = (ptr[1] & 0xff) >> 3;
	voltage |= (ptr[2] & 0x7f) << 5;
	//if (calccrc != sentcrc) { voltage = 0xffff; }
	fprintf(stdout, "V: 0x%04x S: 0x%04X C: 0x%04X\n", voltage, sentcrc, calccrc);
	return voltage;
}

uint16_t ad7280a_decodevoltage_r(uint8_t * ptr) {
	uint16_t voltage;
	uint8_t sentcrc, calccrc;
	uint8_t buf[4];
	sentcrc = ((ptr[3] & 0xff) >> 2) | ((ptr[2] & 0x3) << 6);
	buf[2] = (ptr[2] & 0xff) >> 2;
	buf[2] |= (ptr[1] & 0x3) << 6;
	buf[1] = (ptr[1] & 0xff) >> 2;
	buf[1] |= (ptr[0] & 0x3) << 6;
	buf[0] = (ptr[0] & 0xff) >> 2;
	calccrc = CRC_calculate(buf, 3);
	voltage = (ptr[2] & 0xff) >> 3;
	voltage |= (ptr[1] & 0x7f) << 5;
	//if (calccrc != sentcrc) { voltage = 0xffff; }
	fprintf(stdout, "V: 0x%04x S: 0x%04X C: 0x%04X\n", voltage, sentcrc, calccrc);
	return voltage;
}

uint8_t pkt_a[] = { 0xf2, 0xfa, 0x08, 0xd8 };
uint8_t pkt_b[] = { 0xd8, 0x08, 0xfa, 0xf2 };
uint8_t pkt_c[] = { 0xa0, 0xc4, 0x5a, 0x10 };

int main(int argc, char *argv[]) {
	int16_t crc;
	ad7280a_decodevoltage_r(pkt_a);
	ad7280a_decodevoltage(pkt_b);
	ad7280a_decodevoltage(pkt_c);
}

