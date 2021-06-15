#ifndef XBOT_H
#define XBOT_H

#include "Wire.h"
#include "Arduino.h"
#include "setting.h"
#include "esp32BLEUtilities.h"
#include "Tone32.h"
#include "pca9685.h"
class xbot{
	private:
		Pca9685 pca;
		Tone32 tone32;
	public:
		void init();
		void tone(unsigned int frequency, unsigned long duration);
		void noTone();
};

#endif