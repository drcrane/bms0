#ifndef __AD7280A_H
#define __AD7280A_H

#include <stdint.h>

#define AD_PORT  P3OUT
#define AD_CS    BIT6
#define AD_CNVST BIT5
#define AD_PD    BIT7

uint16_t ad7280a_decodevoltage(uint8_t * ptr);
void ad7280a_rw(uint8_t * buf, uint8_t dev, uint8_t reg, uint8_t val, uint8_t write_all);
//uint32_t ad7280a_write(uint8_t dev, uint8_t reg, uint8_t val, uint8_t write_all);

#endif // __AD7280A_H
