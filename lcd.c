#include "lcd.h"

#include <stdio.h>
#include <string.h>

/* PINOUT CONFIGURATION
 * P2.4 to P2.7 -> DB4 to DB7
 * P3.6 -> RS
 * P5.2 -> RW
 * P5.0 -> E (enable)
 */

void enable() {
    P5->OUT |= BIT0;     // turn enable on
    __delay_cycles(30);  // 10 us
    P5->OUT &= ~BIT0;    // turn enable off
}

void command_LCD(char i) {
    P2->OUT = i;       // higher 4 bits of command on DB4 to DB7
    P3->OUT &= ~BIT6;  // set RS low for instruction input mode
    P5->OUT &= ~BIT2;  // set RW low to write instruction
    enable();
    i = i << 4;   // set the rest of the command to higher 4 bits
    P2->OUT = i;  // set rest of command to DB4 to DB7
    enable();
}

/* STEPS TO INITIALIZE LCD
 *
 *
 * 1. Wakeup Routine
 *
 * 2. Function Set: 0010 10XX or 0x28
 *    DL = 0; 4-bit interface data
 *    N = 1; 2-line display
 *    F = 0; 5x8 font
 *    2 LSBs don't matter
 *
 * 3. Cursor or Display Shift 0001 0000 or 0x10
 *    S/C = 0;
 *    R/L = 0; Shift cursor left
 *
 * 4. Display on/off control: 0000 1111 or 0x0F
 *    D = 1; Display on
 *    C = 1; Cursor on
 *    B = 1; Blinking on
 *
 * 5. Entry mode set: 0000 0110 or 0x06
 *    I/D = 1; Increment DDRAM address
 *    S = 0;
 *
 */

void init_LCD() {
    // Step 1
    P2->OUT = 0;
    delay_ms(40);  // 40 ms
    P2->OUT = 0x30;
    delay_ms(5);  // 5 ms
    enable();
    delay_us(160);  // 160 us
    enable();
    delay_us(160);  // 160 us
    enable();
    delay_us(160);  // 160 us
    P2->OUT = 0x20;
    enable();

    command_LCD(0x28);  // step 2
    command_LCD(0x10);  // step 3
    command_LCD(0x0F);  // step 4
    command_LCD(0x06);  // step 5
}

void clear_LCD() {
    delay_us(10);
    command_LCD(0b1);  // clear display
}

void home_LCD() {
    delay_us(10);
    command_LCD(0b10);  // return cursor to home position
}

void write_char_LCD(char i) {
    delay_ms(1);
    P2->OUT = i;       // load first 4 bits to DB4 to DB7
    P3->OUT |= BIT6;   // set RS high for data input mode
    P5->OUT &= ~BIT2;  // set RW low to write data
    enable();
    i = i << 4;   // set the rest of the data to higher 4 bits
    P2->OUT = i;  // set rest of data to DB4 to DB7
    enable();
}

void write_string_LCD(char* string) {
    int i, size;
    size = strlen(string);

    for (i = 0; i < size; i++) {
        write_char_LCD(*string);
        string += 1;
    }
}
