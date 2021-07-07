#include "xcontroller.h"

void setup() {
  Serial.begin(115200);
  BLE.begin("OhStem-xController"); 
  delay(10);
  Serial.println("Setup Done!");
}

void loop(){
  if(BLE.isConnected())
  {
    while(BLE.available())
    {
      char data = BLE.read();
      Serial.println(data);
      BLE.write(data);
    }
  }
}