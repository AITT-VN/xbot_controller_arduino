void setup() {
  Serial.begin(9600); // khởi tạo cổng serial tốc độ 9600 để xuất ra thông tin
}

void loop() {
  Serial.println("Hello World"); // xuất ra cổng Serial dòng chữ Hello World
  delay(1000); // tạm dừng chương trình 1 giây
}
