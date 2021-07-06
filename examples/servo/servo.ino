#include <xcontroller.h>

Servos s;
// the setup function runs once when you press reset or power the board
void setup() {
  
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 180; i++){
    for (uint8_t pwmnum=0; pwmnum < 8; pwmnum++) {
        s.position(pwmnum, i);
    }
  }
  delay(1000); 
}