#include <8051.h>
#include "oled.h"
#include "pin_config.h"

#define OLED_ADDR  0x3C

/* -------- I2C bits-bang -------- */

static void i2c_delay(void)
{
    unsigned char i;
    for (i = 0; i < 10; i++);
}

static void i2c_start(void)
{
    OLED_SDA = 1;
    OLED_SCL = 1;
    i2c_delay();
    OLED_SDA = 0;
    i2c_delay();
    OLED_SCL = 0;
}

static void i2c_stop(void)
{
    OLED_SDA = 0;
    OLED_SCL = 1;
    i2c_delay();
    OLED_SDA = 1;
}

static void i2c_write(unsigned char dat)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        OLED_SDA = (dat & 0x80) ? 1 : 0;
        OLED_SCL = 1;
        i2c_delay();
        OLED_SCL = 0;
        dat <<= 1;
    }
    OLED_SCL = 1;  // ACK clock
    i2c_delay();
    OLED_SCL = 0;
}

/* -------- OLED commands -------- */

static void oled_cmd(unsigned char cmd)
{
    i2c_start();
    i2c_write(OLED_ADDR << 1);
    i2c_write(0x00);
    i2c_write(cmd);
    i2c_stop();
}

static void oled_data(unsigned char dat)
{
    i2c_start();
    i2c_write(OLED_ADDR << 1);
    i2c_write(0x40);
    i2c_write(dat);
    i2c_stop();
}

void OLED_Init(void)
{
    OLED_SCL = 1;
    OLED_SDA = 1;

    oled_cmd(0xAE);
    oled_cmd(0xA8); oled_cmd(0x3F);
    oled_cmd(0xD3); oled_cmd(0x00);
    oled_cmd(0x40);
    oled_cmd(0xA1);
    oled_cmd(0xC8);
    oled_cmd(0xDA); oled_cmd(0x12);
    oled_cmd(0x81); oled_cmd(0x7F);
    oled_cmd(0xA4);
    oled_cmd(0xA6);
    oled_cmd(0xD5); oled_cmd(0x80);
    oled_cmd(0x8D); oled_cmd(0x14);
    oled_cmd(0xAF);

    OLED_Clear();
}

void OLED_Clear(void)
{
    unsigned char page, col;
    for (page = 0; page < 8; page++)
    {
        OLED_SetCursor(page, 0);
        for (col = 0; col < 128; col++)
            oled_data(0x00);
    }
}

void OLED_SetCursor(unsigned char page, unsigned char col)
{
    oled_cmd(0xB0 | page);
    oled_cmd(0x00 | (col & 0x0F));
    oled_cmd(0x10 | (col >> 4));
}

/* TEMPORARY: fixed text only */
void OLED_Print(const char *s)
{
    while (*s)
    {
        oled_data(*s++); // placeholder   STEP 14 will fix font
    }
}

void OLED_Refresh(void)
{
    // not used yet
}
