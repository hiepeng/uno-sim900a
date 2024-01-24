int incomingByte = 0;   // dùng để lưu giá trị được gửi
String inputString; 
#define NUT A5
#define LEDTT 13  // LED BA0
String SDT1="84975122195";  //SDT CHINH
void setup() {


  pinMode(NUT, INPUT_PULLUP);
    pinMode(LEDTT,OUTPUT);
  digitalWrite(LEDTT,0);delay(200);
  
     for(int a=0;a<20;a++)   //Doi 20s cho co song'
 { 
  digitalWrite(LEDTT,0);delay(500);
  digitalWrite(LEDTT,1);delay(500);
 }


  
        Serial.begin(9600);     // mở serial với baudrate 9600

         Serial.print("AT\r\n");//gui lenh AT test SIM  
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);

  Serial.print("AT\r\n");//gui lenh AT test SIM 
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("ATE0\r\n");// OFF nhai
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("AT+CSCS=\"GSM\"\r\n");              
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("AT+CMGF=1\r\n");              // Bắt đầu quá trình gửi tin nhắn
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("AT+CNMI=2,2,0,0,0\r\n");  
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("AT+CMGDA=\"DEL ALL\"\r\n");    
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250); 
  Serial.print("AT+CLIP=1\r\n");    
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  Serial.print("AT&W\r\n");     
  digitalWrite(LEDTT,0);delay(50);
  digitalWrite(LEDTT,1);delay(250);
  
}


void guitinnhan(String sdtnhan,String noidung)
{ 

  Serial.print("AT+CMGS=\"");delay(200);
  Serial.print(sdtnhan) ;delay(200);
  Serial.println("\"")  ;delay(200);
  Serial.print(noidung) ;delay(200);
  Serial.write(26)      ;delay(200);     // Kết thúc lênh gửi
 
}

void loop() 
{

  if( digitalRead(NUT) == 0 )
    { 
       digitalWrite(LEDTT,1);delay(100); 
       digitalWrite(LEDTT,0);delay(100);
       guitinnhan(SDT1,"HELLO");delay(2000);
       while( digitalRead(NUT) == 0 );
       delay(1000);
    }
    
        // Serial.print("AT\r\n");//gui lenh AT test SIM  
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

// su dung nut nhan vat ly 
// cam a5 voi nut
// chan con lai cua nut nhan voi gnd