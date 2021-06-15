#include "xBot.h"

xbot x;

void setup() {
    Serial.begin(115200);
    x.init();
    delay(10);
    Serial.println("Setup Done!");
}

void loop() {
    x.tone(NOTE_C4, 500);
    delay(200);
    x.noTone();
    delay(200);
}
