#include "xBot.h"

xbot x;
Servos s;
int pwm_num = 0;

void setup() {
    Serial.begin(115200);
    x.init();
    delay(10);
    Serial.println("Setup Done!");
}

void loop(){
    for (int i = 0; i < 180; i++){
        for (uint8_t pwmnum=0; pwmnum < 8; pwmnum++) {
            s.position(pwm_num, i);
        }
    }    
}

