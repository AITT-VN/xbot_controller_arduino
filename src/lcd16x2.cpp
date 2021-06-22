#include "lcd16x2.h"

Lcd::Lcd(uint8_t port) : LiquidCrystal_I2C(0x20, 16, 2), Port(port){
    scl_pin = pin1();
    sda_pin = pin2(); 
}

Lcd::Lcd(uint8_t port, uint8_t addr, uint8_t cols, uint8_t rows) : LiquidCrystal_I2C(addr, cols, rows), Port(port){
    scl_pin = pin1();
    sda_pin = pin2(); 
}

void Lcd::lcd_begin(void){
    init(sda_pin, scl_pin, 100000);
}