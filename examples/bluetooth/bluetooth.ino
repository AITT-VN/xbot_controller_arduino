#include <Wire.h>
#include "xBot.h"

void setup() {
  Serial.begin(115200);
  BLE.begin("xBot Arduino"); 
  delay(10);
  Serial.println("Setup Done!");
}

void loop(){
  if(BLE.available())
	{
    Serial.println("Connected");
		while(BLE.available())
		{
			char data = BLE.read();
      Serial.println(data);
    }
	}
}