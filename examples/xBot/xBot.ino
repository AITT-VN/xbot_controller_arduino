#include "xBot.h"

Servos s;
Motors m;
xbot x;

void setup() {
    Serial.begin(115200);
    BLE.begin("xBot Arduino"); 
    x.init();
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
                x.tone(NOTE_C4, 500);
            } 
            else if (data == 55) {
                m.move(7, 50);
                s.position(0, 180);
                digitalWrite(PORT3_1, LOW);
                x.noTone();
            } 
            else m.move(0, 0);
	    }
	}
}