#include <Wire.h>
#include <AITT_PWMServoDriver.h>
#include "xBot.h"

// called this way, it uses the default address 0x40
AITT_PWMServoDriver pca9685 = AITT_PWMServoDriver();

Servos s;
int pwm_num = 0;

void setup() {
  Serial.begin(115200);
  pca9685.begin();
  pca9685.setPWMFreq(50); 
  delay(10);
  Serial.println("Setup Done!");
}

void loop(){
    for (int i = 0; i < 180; i++){
        for (uint8_t pwmnum=0; pwmnum < 8; pwmnum++) {
            s.position(pwm_num, i);
        }
    }    
}

