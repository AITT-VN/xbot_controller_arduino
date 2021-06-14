#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "xBot.h"


Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();
//Servos servos;
Motors m;
Servos s;

void setup() {
  Serial.begin(115200);
  BLE.begin("xBot Arduino");
  pca9685.begin();
	//pca9685.setOscillatorFrequency(27000000);
	pca9685.setPWMFreq(50); 
  delay(10);
  pinMode(PORT3_1, OUTPUT);
  Serial.println("Setup Done!");
}

void loop() {
  if(BLE.available())
	{
    Serial.println("Connected");
		//isDeviceConnected = true;
		while(BLE.available())
		{
			byte data=BLE.read();
      //Serial.println(data);
      if (data == 51) {
        m.move(3, 90);
        s.position(0, 0);
        digitalWrite(PORT3_1, HIGH);
        tone(NOTE_C4, 500);
      } else if (data == 55) {
        m.move(7, 50);
        s.position(0, 180);
        digitalWrite(PORT3_1, LOW);
        noTone();
      } else m.move(0, 0);
		}
	}
}