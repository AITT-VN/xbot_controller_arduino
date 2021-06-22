#ifndef XBOT_H
#define XBOT_H

#include "Wire.h"
#include "Arduino.h"
#include "setting.h"
#include "esp32BLEUtilities.h"
#include "Tone32.h"
#include "pca9685.h"
#include "led.h"
#include "lcd16x2.h"
#include "port.h"

/*********************  Xbot Board GPIO Map *********************************/
Sig_t Port_Digital[6] =
{
  {18, 19}, {4, 5}, {13, 14}, {16, 17}, {32, 33}, {25, 26},
};

class xbot{
	private:
		Pca9685 pca;
		Tone32 tone32;
		Led led;
	public:
		void init();
		void tone(unsigned int frequency, unsigned long duration);
		void noTone();
		void show_led(int index, String color);
		void led_off(int index);
};

#endif