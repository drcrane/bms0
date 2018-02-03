#include <msp430.h>
#include <stdint.h>
#include <stdio.h>

#include "ad7280a.h"
#include "spifn.h"
#include "crcfn.h"
#include "utilityfn.h"

#ifdef INCLUDE_ad7280a_validate
uint16_t ad7280a_validate(uint8_t * buf, uint16_t * voltage) {
	
}
#endif // INCLUDE_ad7280a_write

#ifdef INCLUDE_ad7280a_write
uint32_t ad7280a_write(uint8_t dev, uint8_t reg, uint8_t val, uint8_t write_all) {
	uint8_t buf[4];
	uint32_t retv;
	P1OUT &= ~AD_CS;
	buf[0] = dev;
	buf[1] = reg << 2;
	buf[1] |= (val >> 6);
	buf[2] = (val << 2);
	if (write_all) buf[2] |= 2;
	buf[3] = CRC_calculate(buf, 3);
	buf[0] = dev << 3;
	buf[0] |= reg >> 3;
	buf[1] = reg << 5;
	buf[1] |= val >> 3;
	// buf[2] = val << 5
	buf[2] = buf[2] << 3;
	buf[2] |= buf[3] >> 5;
	if (write_all) {
		buf[2] |= 0x10;
	}
	buf[3] <<= 3;
	buf[3] |= 0x2;
	buf[0] = SPI_rw(buf[0]);
	buf[1] = SPI_rw(buf[1]);
	buf[2] = SPI_rw(buf[2]);
	buf[3] = SPI_rw(buf[3]);
	retv = 0L;
	retv |= ((uint32_t)buf[0] & 0xff) << 24;
	retv |= ((uint32_t)buf[1] & 0xff) << 16;
	retv |= ((uint32_t)buf[2] & 0xff) << 8;
	retv |= buf[3] & 0xff;
	P1OUT |= AD_CS;
	Utility_delay(1);
	return retv;
}
#endif // INCLUDE_ad7280a_write

