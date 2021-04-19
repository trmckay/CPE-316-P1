#include "dco.h"
#include "keypad.h"
#include "lcd.h"

/* WARNING:
 * DO NOT FORGET TO NULL-TERMINATE STRINGS
 * set_pin() and check_pin() rely on the fact that all
 * strings are null terminated.
 */

void init() {
    // Stop watchdog timer.
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    //// LCD I/O configuration ////

    // Set P2.4 to P2.7 as GPIO.
    P2->SEL0 &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    P2->SEL1 &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    // Set P2.4 to P2.7 as output.
    P2->DIR |= (BIT4 | BIT5 | BIT6 | BIT7);

    // Set P3.6 as GPIO.
    P3->SEL0 &= ~BIT6;
    P3->SEL1 &= ~BIT6;
    // Set P3.6 as output.
    P3->DIR |= BIT6;

    //// Keypad I/O configuration ////

    // Set P5.0 and P5.2 as GPIO.
    P5->SEL0 &= ~(BIT0 | BIT2);
    P5->SEL1 &= ~(BIT0 | BIT2);
    // Set P5.0 and P5.2 as output.
    P5->DIR |= (BIT0 | BIT2);

    // Set P4.0 to P4.6 as GPIO.
    P4->SEL0 &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
    P4->SEL1 &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
    // Set P4.0 to P4.3 as output.
    P4->DIR |= (BIT0 | BIT1 | BIT2 | BIT3);
    // Set P4.4 to P4.6 as output.
    P4->DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    init_LCD();
    clear_LCD();
    home_LCD();
}

void main(void) {
    init();

    char cchar = 0;
    uint8_t i = 0;

    char cbuf[MAX_PIN_LENGTH];
    for (int j = 0; j < MAX_PIN_LENGTH; j++) {
        cbuf[j] = 0;
    }

    while (1) {
        write_string_LCD("Enter pin then #");

        // Read in user pin.
        i = 0;
        while (cchar != '#' && i < MAX_PIN_LENGTH) {
            cchar = read_keypad_blking();
            cbuf[i++] = cchar;
        }
        cbuf[i] = 0;

        // Check user pin against correct pin.
        if (check_pin(cbuf)) {
            write_string_LCD("Correct!");
            while (1)
                ;
        }
    }
}
