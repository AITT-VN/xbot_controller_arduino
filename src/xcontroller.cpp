#include "xcontroller.h" 

void xcontroller::init(){
  pca.init();
  led.init();
}

void xcontroller::tone(unsigned int frequency, unsigned long duration){
  tone32.tone(frequency, duration);
}

void xcontroller::noTone(){
  tone32.noTone();
}

void xcontroller::show_led(int index, String color){
  led.show(index, color);
}

void xcontroller::led_off(int index){
  led.off(index);
}