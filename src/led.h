#ifndef _LED_H
#define _LED_H

#include "AITT_NeoPixel.h"

/*
Parameters:
r – Red brightness, 0 to 255.
g – Green brightness, 0 to 255.
b – Blue brightness, 0 to 255.
*/

class Led
{
    private:
        int NEOPIXEL_NUM = 2;
        int NEOPIXEL_PIN = 12;
        int brightness = 50;
        AITT_NeoPixel _np = AITT_NeoPixel( NEOPIXEL_NUM, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

    public:
        void init();
        void show(int index, String color);
        void off(int index);
} ;

#endif