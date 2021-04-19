#include "delay.h"

void delay_us(uint16_t us) {  // minimum range: 10 us
    uint16_t i;
    uint32_t iters;

    // Number of 1 us divisions to wait.
    iters = DCO_FREQ * us / 1000000;

    // Delay...
    for (i = 0; i < iters; i++) {
        __delay_cycles(1);
    }
}

void delay_ms(uint16_t ms) {  // minimum range: 1 ms
    uint16_t i;
    uint32_t iters;

    // Number of 1 us divisions to wait.
    iters = DCO_FREQ * ms / 1000000;

    // Delay...
    for (i = 0; i < iters; i++) {
        __delay_cycles(1000);
    }
}
