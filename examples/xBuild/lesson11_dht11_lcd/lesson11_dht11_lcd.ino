#include <LCD_1602.h>
#include <DHTesp.h>
            
const int DHTPIN = D2_1;

DHTesp dht;
LCD_1602 lcd(0x21);

void setup() {
  lcd.begin(D1_1, D1_2);
  lcd.backlight();
  dht.setup(DHTPIN, DHTesp::DHT11);
}
void loop() {
    // chờ 2s giữa các lần đọc cảm biến
    delay(2000);
    lcd.clear();
    float h = dht.getHumidity();
    float t = dht.getTemperature();
    if (dht.getStatus() != 0) {
      lcd.print("Read sensor failed!");
      return;
    }
    lcd.setCursor(0, 0);
    lcd.print("Temp:     ");
    lcd.print(t);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");
}
