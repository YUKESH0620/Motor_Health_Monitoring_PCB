#include "num_print.h"
#include "oled.h"

void OLED_PrintUInt(unsigned int val)
{
    char buf[6];
    char i = 0;
    char out[2];
    out[1] = '\0';

    if (val == 0)
    {
        OLED_Print("0");
        return;
    }

    while (val > 0 && i < 5)
    {
        buf[i++] = (val % 10) + '0';
        val /= 10;
    }

    
while (i--)
{
    out[0] = buf[i];
    OLED_Print(out);
}

}
