#include "xBot.h" 

void xbot::init(){
  pca.init();
  led.init();
}

void xbot::tone(unsigned int frequency, unsigned long duration){
  tone32.tone(frequency, duration);
}

void xbot::noTone(){
  tone32.noTone();
}

void xbot::show_led(int index, String color){
  led.show(index, color);
}

void xbot::led_off(int index){
  led.off(index);
}