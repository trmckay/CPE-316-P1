#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "msp.h"
#include "util.h"

// KEYPAD_PORT.0 - KEYPAD_PORT.6 must be free.
#define KEYPAD_PORT P4

#define KEYPAD_WIDTH 3
#define KEYPAD_HEIGHT 3

static char KEYPAD_CHARS[12] = {'1', '2', '3', '4', '5', '6',
                                '7', '8', '9', '*', '0', '#'};

void keypad_cfg();
uint8_t read_keypad();
uint8_t read_keypad_non_blking();

#endif
