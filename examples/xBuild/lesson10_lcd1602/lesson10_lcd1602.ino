#include <LCD_1602.h>

LCD_1602 lcd(0x21);

void setup() {
    lcd.begin(D1_1, D1_2);
    lcd.backlight();
}

void loop(){
    lcd.setCursor(0, 0);
    lcd.print("OhStem");
    lcd.setCursor(0, 1);
    lcd.print("xin chao ban!"); 
    delay(2000);
    lcd.clear();
    delay(1000);
}
