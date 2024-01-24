int incomingByte = 0;   // dùng để lưu giá trị được gửi
String inputString; 
void setup() {
        Serial.begin(9600);     // mở serial với baudrate 9600
}

void loop() 
{
         Serial.print("AT\r\n");//gui lenh AT test SIM  
        delay(1000);
  
        // nếu còn có thể đọc được 
      if (Serial.available() > 0)
      {
             delay(500);// wait data
       inputString="";
       while (Serial.available()) 
       {
          char inChar = (char)Serial.read();
          inputString += inChar;
       }
       Serial.print(inputString);
       
     }
}