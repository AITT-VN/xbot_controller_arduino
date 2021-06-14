/*************************************************** 
  This is an example for our AITT 16-channel PWM & Servo driver
  PWM test - this will drive 16 PWMs in a 'wave'

  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Huy tran for AITT Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <AITT_PWMServoDriver.h>
#include "xBot.h"

// called this way, it uses the default address 0x40
AITT_PWMServoDriver pca9685 = AITT_PWMServoDriver();

Motors m;
    /*
        calculate direction based on angle
            *         90(3)
            *   135(4) |  45(2)
            * 180(5)---+----Angle=0(dir=1)
            *   225(6) |  315(8)
            *         270(7)
    */

void setup() {
  Serial.begin(115200);
  pca9685.begin();
  pca9685.setPWMFreq(50); 
  delay(10);
  Serial.println("Setup Done!");
}

void loop(){
    m.move(3, 90);
    delay(2000);
    m.move(7, 50);
    delay(2000);
}
