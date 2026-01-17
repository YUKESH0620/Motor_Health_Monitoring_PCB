#ifndef KEYPAD_H
#define KEYPAD_H

// returns key number 1–16, or 0 if no key
unsigned char Keypad_GetKey(void);
void Keypad_Init(void);

#endif
