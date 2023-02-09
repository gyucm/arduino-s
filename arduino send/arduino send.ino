#include <SoftwareSerial.h>  //0하고1외 추가 /송신

SoftwareSerial P_Serial(6,7); //6번7번 RXTX로 사용 / 0하고 1에 기존 시리얼

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600); //0,1qjvls 값뜨는지 확인용
  P_Serial.begin(9600);//6,7번핀 6,7번으로 발송 
}

void loop() {
  // put your main code here, to run repeatedly:
int i = 50, j = 20; //ex 온도 습도
String sensing1 = (String)i;
String sensing2 = (String)j;//아스키 코드로 바뀌기 때문에 임의로 바꿈
String str = (String)sensing1 + "#" + (String)sensing2;
//Serial.println(str);
delay(100);
}
