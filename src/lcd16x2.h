#ifndef _LCD16x2_H
#define _LCD16x2_H

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"
#include "port.h"

#define I2C_ERROR           (-1)
#define LCD_DEFAULT_ADDRESS (0x20)

class Lcd : public LiquidCrystal_I2C, Port
{
    private:
        int self_port = 0;
        int scl_pin, sda_pin;

    public:
        Lcd(uint8_t port);
        Lcd(uint8_t port, uint8_t addr, uint8_t cols, uint8_t rows);
        void lcd_begin(void);
} ;

#endif