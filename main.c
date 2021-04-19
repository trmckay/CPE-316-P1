#include "dco.h"
#include "lcd.h"

/* PINOUT CONFIGURATION
 * P2.4 to P2.7 -> DB4 to DB7
 * P3.6 -> RS
 * P5.2 -> RW
 * P5.0 -> E
 */
void init_IO() {
    // Stop watchdog timer.
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Set P2.4 to P2.7 as general purpose I/O.
    P2->SEL0 &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    P2->SEL1 &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    // Set P2.4 to P2.7 as output.
    P2->DIR |= (BIT4 | BIT5 | BIT6 | BIT7);

    // Set P3.6 as general purpose I/O.
    P3->SEL0 &= ~BIT6;
    P3->SEL1 &= ~BIT6;
    // Set P3.6 as output.
    P3->DIR |= BIT6;

    // Set P5.0 and P5.2 as general purpose I/O.
    P5->SEL0 &= ~(BIT0 | BIT2);
    P5->SEL1 &= ~(BIT0 | BIT2);
    // Set P5.0 and P5.2 as output.
    P5->DIR |= (BIT0 | BIT2);
}

void main(void) {
    init_IO();
    init_LCD();
    clear_LCD();
    home_LCD();
    write_string_LCD("Hello World");
}
