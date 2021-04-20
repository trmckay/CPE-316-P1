#include "lock.h"

static char corr_pin[PIN_LENGTH + 1] = {'1', '2', '3', '4'};

int check_pin(char* user_pin) {
    char cchar_user = user_pin[0];
    char cchar_corr = corr_pin[0];
    int i = 1;

    while (i < PIN_LENGTH) {
        if (cchar_user != cchar_corr) {
            return 0;
        }
        cchar_user = user_pin[i];
        cchar_corr = corr_pin[i++];
    }
    return 1;
}
