#ifndef _DCO_H
#define _DCO_H

#include "msp.h"

#define FREQ_1p5_MHZ 1500000
#define FREQ_3_MHZ 3000000
#define FREQ_6_MHZ 6000000
#define FREQ_12_MHZ 12000000
#define FREQ_24_MHZ 24000000

#define DCO_FREQ FREQ_3_MHZ

void set_DCO(uint32_t FREQ);

#endif
