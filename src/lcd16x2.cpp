#include "lcd16x2.h"

int PORTS_DIGITAL[6][2] = {{18, 19}, {4, 5}, {13, 14}, {16, 17}, {32, 33}, {25, 26}};

Lcd::Lcd(int port){
    Liquid_I2C(0x27, 16, 2);
    if ((port > 5) || (port < 0)){
        Serial.println("Port not supported");
    } 
    _reset_port(port);
}

Lcd::Lcd(int port, uint8_t addr, uint8_t cols, uint8_t rows){
    Liquid_I2C(addr, cols, rows);
    if ((port > 5) || (port < 0)){
        Serial.println("Port not supported");
    } 
    _reset_port(port);
}

void Lcd::_reset_port(int port){
    self_port = port;
    scl_pin = PORTS_DIGITAL[port][0];
    sda_pin = PORTS_DIGITAL[port][1]; 
    _init(sda_pin, scl_pin);
}

void Lcd::_check_port(int port){
    if (port != self_port){
        _reset_port(port);
    }
}

void Lcd::init(int port){
    _check_port(port);
    backlight();
}
