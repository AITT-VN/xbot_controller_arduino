int LEDPin = D1_1; // Module LED nối vào cổng số 1
int rotaryPin = A4_1; // Module rotary nối vào cổng số 4
int rotaryValue = 0; 

// khai cấu hình PWM
const int frequency = 5000;
const int pwmChannel = 0; // channel bất kỳ 0-15
const int resolution = 12;
 
void setup(){
  // cấu hình và khởi tạo PWM
  ledcSetup(pwmChannel, frequency, resolution);
  
  // gắn PWM với chân IO của đèn LED
  ledcAttachPin(LEDPin, pwmChannel);
}
 
void loop() {
  // đọc giá trị cảm biến
  rotaryValue = analogRead(rotaryPin);
  // thay đổi tín hiệu PWM
  ledcWrite(pwmChannel, rotaryValue);
}
