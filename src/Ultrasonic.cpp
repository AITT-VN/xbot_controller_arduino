/*
  HCSR04 - Library for arduino, for HC-SR04 ultrasonic distance sensor.
  Created by Martin Sosic, June 11, 2016.
*/

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(
        int triggerPin, int echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

double Ultrasonic::measureDistanceCm() {
    //Using the approximate formula 19.307°C results in roughly 343m/s which is the commonly used value for air.
    return measureDistanceCm(19.307);
}

double Ultrasonic::measureDistanceCm(float temperature) {
    // Make sure that trigger pin is LOW.
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
    unsigned long durationMicroSec = pulseIn(echoPin, HIGH);

    double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * temperature; // Cair ≈ (331.3 + 0.606 ⋅ ϑ) m/s
    double distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMs;
    if (distanceCm == 0 || distanceCm > 400) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
}

UltrasonicAndLed::UltrasonicAndLed(uint8_t ultra_pin, uint8_t led_pin)
{
	_pin = ultra_pin;
    Ledpin = led_pin;
}
/*The measured distance from the range 0 to 400 Centimeters*/
long UltrasonicAndLed::MeasureInCentimeters(void)
{
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin,LOW);
	pinMode(_pin,INPUT);
	long duration;
	duration = pulseIn(_pin,HIGH);
	long RangeInCentimeters;
	RangeInCentimeters = duration/29/2;
	return RangeInCentimeters;
}
void UltrasonicAndLed::showLed(uint8_t r, uint8_t g, uint8_t b) {
    for (int i=0; i< NUMPIXELS; i++){
        Ultra_led.setPixelColor(i, r, g, b);
        Ultra_led.show();
        }
}
