#include "keypad.h"

char _read_keypad() {
    int r, c;

    for (r = 0; r < KEYPAD_HEIGHT; r++) {
        // Set R(r) (P.r) high.
        KEYPAD_PORT->OUT |= (BIT0 << r);
        KEYPAD_PORT->OUT &= (BIT0 << r);

        for (c = 0; c < KEYPAD_WIDTH; c++) {
            // Poll C(c).
            if (KEYPAD_PORT->IN & (BIT4 << c)) {
                // Lookup and return char for this key.
                return KEYPAD_CHARS[(r * KEYPAD_WIDTH) + c];
            }
        }
    }

    return 0;
}

char read_keypad_blking() {
    char ch = 0;

    while (ch == 0) {
        ch = _read_keypad();
    }

    return ch;
}

char read_keypad_non_blking() {
    return _read_keypad();
}
