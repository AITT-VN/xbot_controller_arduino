#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "xBot.h"
#include "setting.h"

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();
//Servos servos;
Motors m;

void setup() {
  Serial.begin(115200);
  pca9685.begin();
	//pca9685.setOscillatorFrequency(27000000);
	pca9685.setPWMFreq(50); 
  delay(10);
}

void loop() {
  Serial.println("begin");
  m.move(3, 90);
  delay(3000);
  m.move(0, 0);
  delay(3000);
  m.move(7, 50);
  delay(3000);
  /*
  Serial.println("begin");
  for (uint16_t degrees = 0; degrees < 180; degrees++) {
    delay(1);
    servos.position(0, degrees);
  }
  delay(1000);
  for (uint16_t degrees = 180; degrees > 0; degrees--) {
    delay(1);
    servos.position(0, degrees);
  }
  delay(1000);
  */
}