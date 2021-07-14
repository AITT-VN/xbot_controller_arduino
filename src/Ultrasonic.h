/*
  HCSR04 - Library for arduino, for HC-SR04 ultrasonic distance sensor.
  Created by Martin Sosic, June 11, 2016.
*/

#ifndef Ultrasonic_H
#define Ultrasonic_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 8

class Ultrasonic 
{
 public:
    /**
     * @param triggerPin  Digital pin that is used for controlling sensor (output).
     * @param echoPin  Digital pin that is used to get information from sensor (input).
     */
    Ultrasonic(int triggerPin, int echoPin);

    /**
     * Measures distance by sending ultrasonic waves and measuring time it takes them
     * to return.
     * @returns Distance in centimeters, or negative value if distance is greater than 400cm.
     */
    double measureDistanceCm();

    /**
     * Measures distance by sending ultrasonic waves and measuring time it takes them
     * to return.
     * @param temperature  Temperature in degrees celsius
     * @returns Distance in centimeters, or negative value if distance is greater than 400cm.
     */
    double measureDistanceCm(float temperature);
 private:
    int triggerPin, echoPin;
};

class UltrasonicAndLed
{
	public:
		UltrasonicAndLed(uint8_t ultra_pin, uint8_t led_pin);
		long MeasureInCentimeters(void);
		long MeasureInInches(void);
      void showLed(uint8_t r, uint8_t g, uint8_t b);
	private:      
		int _pin;   //pin number that is connected with SIG pin of Ultrasonic Ranger.
		int Ledpin; //pin number that is connected with LED pin of Ultrasonic Ranger.
      Adafruit_NeoPixel Ultra_led = Adafruit_NeoPixel(NUMPIXELS, uint8_t (Ledpin), NEO_GRB + NEO_KHZ800);
};

#endif // Ultrasonic_H
