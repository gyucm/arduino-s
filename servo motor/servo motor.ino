#include <Servo.h> //모터
Servo servo;

void setup() {
 pinMode(5, OUTPUT); //5번 출력
 servo.attach(5); //5번에서 모터 출력
 Serial.begin(9600); 
}

void loop() {
  for(int i = 0; i<180; i++) //180도 회전
  {
    servo.write(i); //모터 회전
    Serial.println(i);
    delay(10);
  }
}