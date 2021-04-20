#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "msp.h"

// KEYPAD_PORT.0 - KEYPAD_PORT.7 must be free.
#define KEYPAD_PORT P4

#define KEYPAD_WIDTH 4
#define KEYPAD_HEIGHT 4

static char KEYPAD_CHARS[KEYPAD_WIDTH * KEYPAD_HEIGHT] = {
    '1', '2', '3', 'A', '4', '5', '6', 'B',
    '7', '8', '9', 'C', '*', '0', '#', 'D'};

char read_keypad_non_blking();
char read_keypad_blking();

#endif
