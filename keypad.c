#include "keypad.h"

void keypad_cfg() {
    // Configure row outputs.
    CONFIG_PORT(KEYPAD_PORT, BIT0, OUTPUT)  // KEYPAD_PORT.0: R1, output
    CONFIG_PORT(KEYPAD_PORT, BIT1, OUTPUT)  // KEYPAD_PORT.1: R2, output
    CONFIG_PORT(KEYPAD_PORT, BIT2, OUTPUT)  // KEYPAD_PORT.2: R3, output
    CONFIG_PORT(KEYPAD_PORT, BIT3, OUTPUT)  // KEYPAD_PORT.3: R4, output

    // Configure column inputs.
    CONFIG_PORT(KEYPAD_PORT, BIT4, INPUT)  // KEYPAD_PORT.0: C1, input
    CONFIG_PORT(KEYPAD_PORT, BIT5, INPUT)  // KEYPAD_PORT.1: C2, input
    CONFIG_PORT(KEYPAD_PORT, BIT6, INPUT)  // KEYPAD_PORT.2: C3, input
}

char _read_keypad() {
    int r, c;
    for (r = 0; r < 3; r++) {
        // Set R<r> high.
        KEYPAD_PORT->OUT |= (BIT1 << r);
        for (c = 0; c < 2; c++) {
            // Poll C<c>.
            if (KEYPAD_PORT->OUT &= ((BIT1) << (c + 4))) {
                // Lookup and return char for this key.
                return KEYPAD_CHARS[(r * KEYPAD_WIDTH) + c];
            }
        }
    }
    return 0;
}

char read_keypad_blking() {
    char ch = 0;
    while (ch != 0) {
        _read_keypad();
    }
    return ch;
}

char read_keypad_non_blking() {
    return _read_keypad();
}
