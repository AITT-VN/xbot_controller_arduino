#ifndef _LCD16x2_H
#define _LCD16x2_H

#include "Arduino.h"
#include "i2c_lcd.h"

class Lcd : public LiquidCrystal_I2C
{
    private:
        int self_port = 0;
        uint8_t scl_pin, sda_pin;

    public:
        Lcd(int port);
        Lcd(int port, uint8_t addr, uint8_t cols, uint8_t rows);
        void _reset_port(int port);
        void _check_port(int port);
        void init(int port);
} ;

#endif