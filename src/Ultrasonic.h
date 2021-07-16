/*
  HCSR04 - Library for arduino, for HC-SR04 ultrasonic distance sensor.
  Created by Martin Sosic, June 11, 2016.
*/

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

class Ultrasonic{
 public:
    /**
     * @param triggerPin  Digital pin that is used for controlling sensor (output).
     * @param echoPin  Digital pin that is used to get information from sensor (input).
     */
    Ultrasonic(int triggerPin, int echoPin);
    double measureDistanceCm();
    double measureDistanceMm();
 private:
    int triggerPin, echoPin;
};

#endif // ULTRASONIC_H
