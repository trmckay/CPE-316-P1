#ifndef LCD_H_
#define LCD_H_

#include "delay.h"

void enable();
void command_LCD(char i);
void init_LCD();

void clear_LCD();
void home_LCD();
void write_char_LCD(char i);
void write_string_LCD(char* string);

#endif
