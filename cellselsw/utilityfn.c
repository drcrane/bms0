#include "utilityfn.h"
#include <stdint.h>
#include <msp430.h>

#define size_t int16_t

/*
void * memcpy(void *dst0, const void *src0, size_t len) {
	char *dst = (char *)dst0;
	const char *src = (const char *)src0;
	void *ret = dst0;

	for (; len > 0; len--)
		*dst++ = *src++;

	return ret;
}
*/

uint16_t Utility_countbitsset(uint8_t byte) {
	int i;
	uint16_t count;
	count = 0;
	i = 8;
	while (i--) {
		if (byte & 1) {
			count ++;
		}
		byte >>= 1;
	}
	return count;
}


void Utility_delay(unsigned short int loops) {
	while (loops--) {
		__nop();
	}
}


/**
 * convert the hex value supplied in s into a 32bit integer, terminating on count or \0
 */
unsigned long int Utility_hexToInt(const char* s, int count) {
	unsigned long int ret = 0;
	char c;
	while ((c = *s++) != '\0' && count--) {
		int n = 0;
		if('0' <= c && c <= '9') { n = c-'0'; }
		else if('a' <= c && c <= 'f') { n = 10 + c - 'a'; }
		else if('A' <= c && c <= 'F') { n = 10 + c - 'A'; }
		ret = n + (ret << 4);
	}
	return ret;
}

uint16_t Utility_uint16_beToLe(const void * ptr) {
	uint16_t res;
	res = ((uint16_t)((uint8_t *)ptr)[0]) << 8;
	res |= ((uint8_t *)ptr)[1];
	return res;
}

/**
 * translate count bytes from ptr into ascii hex and store them in the dst array.
 */
extern const char Utility_hexchars[];
void Utility_intToHex(char* dst, const void* ptr, int count) {
	int i;
	const unsigned char* cptr = (const unsigned char*)ptr;
	//const char hexchars[] = "0123456789ABCDEF";
	unsigned int j = (count << 1);
	dst[j] = 0;
	for (i = 0; i < count; i++) {
		dst[--j] = Utility_hexchars[((cptr[i]) & 0xf)];
		dst[--j] = Utility_hexchars[((cptr[i] >> 4) & 0xf)];
	}
}

