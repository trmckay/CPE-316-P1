#ifndef _LOCK_H
#define _LOCK_H

#define MAX_PIN_LENGTH 16

// Set the correct pin to the provided null-terminated string.
void set_pin(char* pin);

// Check the correct pin against the provided null-terminated string.
int check_pin(char* user_pin);

#endif
