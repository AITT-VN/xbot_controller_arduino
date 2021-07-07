#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "Tone32.h"
#include "Motors.h"
#include "Servos.h"
#include "mpu6050.h"
#include "esp32BLEUtilities.h"

#ifndef XCONTROLLER_H
#define XCONTROLLER_H

#define NUMPIXELS_ONBOARD 2

//#include "Wire.h"

//#include "esp32BLEUtilities.h"

//#include "pca9685.h"
//#include "mpu6050.h"
//#include <utility/TM1640.h>
//#include <utility/TM16xxMatrix.h>



class XController
{
  private:
    //Pca9685 pca;
    Adafruit_NeoPixel ledOnboard = Adafruit_NeoPixel(NUMPIXELS_ONBOARD, RGB_LED, NEO_GRB + NEO_KHZ800);

  public:
    XController(void);
    //void init();
    void showLed(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
    void tone(unsigned int frequency, unsigned long duration, uint8_t channel);
    void noTone(uint8_t channel);

};

#endif