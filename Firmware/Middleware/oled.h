#ifndef OLED_H
#define OLED_H

void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(unsigned char page, unsigned char col);
void OLED_Print(const char *str);
void OLED_Refresh(void);

#endif
