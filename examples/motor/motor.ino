#include "xBot.h"

xbot x;
Motors m;
    /*
        calculate direction based on angle
            *         90(3)
            *   135(4) |  45(2)
            * 180(5)---+----Angle=0(dir=1)
            *   225(6) |  315(8)
            *         270(7)
    */

void setup() {
    Serial.begin(115200);
    x.init();
    delay(10);
    Serial.println("Setup Done!");
}

void loop(){
    m.move(3, 90);
    delay(2000);
    m.move(7, 50);
    delay(2000);
}
