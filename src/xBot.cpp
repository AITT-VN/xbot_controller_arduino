#include "xBot.h" 

void xbot::init(){
  pca.init();
}

void xbot::tone(unsigned int frequency, unsigned long duration){
  tone32.tone(frequency, duration);
}

void xbot::noTone(){
  tone32.noTone();
}