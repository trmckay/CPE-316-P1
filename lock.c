#include "lock.h"

static char corr_pin[MAX_PIN_LENGTH + 1];

void set_pin(char* user_pin) {
    char cchar = user_pin[0];
    int i = 1;

    while (cchar != 0 && i < MAX_PIN_LENGTH) {
        corr_pin[i] = cchar;
        cchar = user_pin[i++];
    }

    // Null-terminate pin.
    corr_pin[i] = 0;
}

int check_pin(char* user_pin) {
    char cchar_user = user_pin[0];
    char cchar_corr = corr_pin[0];
    int i = 1;

    while (i < MAX_PIN_LENGTH) {
        if (cchar_user != cchar_corr) {
            return 0;
        }
        cchar_user = user_pin[i];
        cchar_corr = corr_pin[i++];
    }
    return 1;
}
