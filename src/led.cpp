#include "led.h"

void Led::init(){
    _np.begin();
    _np.setBrightness(brightness);
    _np.show();
}

void Led::show(int index, String color){
    uint32_t display_color;
    if (color == "red"){
        display_color = _np.Color(255, 0, 0);
    }
    else if (color == "green"){
        display_color = _np.Color(0, 255, 0);
    }
    else if (color == "blue"){
        display_color = _np.Color(0, 0, 255);
    }
    else{
        display_color = _np.Color(0, 0, 0);
    }

    if (index == 0){
        _np.setPixelColor(0, display_color);
        _np.setPixelColor(1, display_color);
        _np.show();
    }
    else if( (index > 0) && (index < 3)){
        _np.setPixelColor((index - 1), display_color);
        _np.show();
    }
}

void Led::off(int index){
    show(index, "none");
}
