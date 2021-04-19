#include "dco.h"

/* set_DCO changes the DCO clock from the default of 3 MHz to the nominal
 * frequency defined above
 */
void set_DCO(uint32_t FREQ) {
    CS->KEY = CS_KEY_VAL;  // unlock CS registers

    switch (FREQ) {  // set the DCO based on input FREQ
        case FREQ_1p5_MHZ:
            CS->CTL0 = CS_CTL0_DCORSEL_0;  // 1.5 MHZ
            break;
        case FREQ_3_MHZ:
            CS->CTL0 = CS_CTL0_DCORSEL_1;  // 3 MHZ
            break;
        case FREQ_6_MHZ:
            CS->CTL0 = CS_CTL0_DCORSEL_2;  // 6 MHZ
            break;
        case FREQ_12_MHZ:
            CS->CTL0 = CS_CTL0_DCORSEL_3;  // 12 MHZ
            break;
        case FREQ_24_MHZ:
            CS->CTL0 = CS_CTL0_DCORSEL_4;  // 24 MHZ
            break;
        default:
            CS->CTL0 = CS_CTL0_DCORSEL_1;  // default to 3 MHZ
    }

    // select clock sources
    CS->CTL1 = CS_CTL1_SELM_3;  // select MCLK source to be DCO
    CS->KEY = 0;                // lock CS
}
