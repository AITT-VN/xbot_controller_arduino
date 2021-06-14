#include <Wire.h>
#include "xBot.h"

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println("Setup Done!");
}

void loop() {
    tone(NOTE_C4, 500);
    delay(200);
    noTone();
    delay(200);
}
