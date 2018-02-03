#ifndef __AD7280A_H
#define __AD7280A_H

#include <stdint.h>

#define AD_CS    BIT0
#define AD_CNVST BIT1
#define AD_PD    BIT2

uint32_t ad7280a_write(uint8_t dev, uint8_t reg, uint8_t val, uint8_t write_all);

#endif // __AD7280A_H
