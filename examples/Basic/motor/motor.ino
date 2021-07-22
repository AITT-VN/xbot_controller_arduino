#include "Motors.h"

Motors m;

/*
    calculate direction based on angle
        *         90(3)
        *   135(4) |  45(2)
        * 180(5)---+----Angle=0(dir=1)
        *   225(6) |  315(8)
        *         270(7)
*/

// the setup function runs once when you press reset or power the board
void setup() {
  
}

// the loop function runs over and over again forever
void loop() {
  m.speed(100, 100);
  delay(1000);
  m.speed(0, 0);
  delay(1000);
  m.speed(-100, -100);
  delay(1000);
}
