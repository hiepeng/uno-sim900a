#include <SoftwareSerial.h>
#include <String.h>

// Khai báo các chân kết nối với module SIM
#define RX_PIN 0
#define TX_PIN 1

SoftwareSerial simSerial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  simSerial.begin(9600);
  
  // Khởi động module SIM
  simSerial.println("AT");
  delay(1000);
  
  // Đặt chế độ nhận tin nhắn
  simSerial.println("AT+CMGF=1");
  delay(1000);
  
  // Hiển thị số điện thoại của người gửi khi nhận tin nhắn
  simSerial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
}

void loop() {
  if (simSerial.available() > 0) {
    String message = simSerial.readString();
    Serial.println(message);
    delay(1000);
  }
}