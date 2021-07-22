#include <DHTesp.h>
#include <LCD_1602.h>
#include <Mini_Fan.h>

LCD_1602 lcd(0x21); 
DHTesp dht;
MiniFan fan(D3_1, D3_2);

unsigned long lastCheckTemp = 0; // lưu thời gian cập nhật nhiệt độ

void setup(void) {
  Serial.begin(9600);
  lcd.begin(D1_1, D1_2);
  lcd.backlight();
  dht.setup(D2_1, DHTesp::DHT11);
}
void loop(void){
  // lấy thời gian hiện tại
  unsigned long currentMillis = millis();
  if (currentMillis - lastCheckTemp >= 5000) {
    // đã quá 5s kể từ lần cập nhật nhiệt độ cuối
    // cần cập nhật lại
    lastCheckTemp = currentMillis;
    lcd.clear();
    float h = dht.getHumidity();
    float t = dht.getTemperature();
    if (dht.getStatus() != 0) {
      lcd.print("Read sensor faiLED!");
      return;
    }
    lcd.setCursor(0, 0);
    lcd.print("Temp:     "); lcd.print(t); lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: "); lcd.print(h); lcd.print("%");
    if (t < 32){
      Serial.println("Tắt quạt");
      fan.off();
    } else{
      Serial.println("Bật quạt");
      fan.on();
    }
  }
}
