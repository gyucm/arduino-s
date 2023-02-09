#include <SoftwareSerial.h> //아두이노 수신
#include <Stepper.h>

SoftwareSerial P_Serial(6,7);
unsigned long current = 0;
unsigned long previous = 0;

char str[50]; //전체값저장
char *sArr[4]; //각각의 세싱 값 저장하는 변수
int stepsPerRev = 2048; //한바퀴
Stepper stepper (stepsPerRev, 11,9,10,8);

void setup() {
  Serial.begin(9600);
  P_Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  stepper.setSpeed(18);
}

void loop() {
  // put your main code here, to run repeatedly:
  int turn =0;
  int index = 0, i=0;
  char * ptr = NULL;
  while(P_Serial.available())
  {
    str[index++]=P_Serial.read();
  }
  str[index] = '\0';
  ptr = strtok(str, "#"); //공백을 쪼개서 적용 구분자는 샵 

  while(ptr != NULL)
  {
    sArr[i++] = ptr;
    ptr = strtok(NULL, " "); //널일때까지 쪼갬 공백이 구분자 /구분자는 상관없으나 통일이 좋음
  }
  int a = atoi(sArr[0]);
  int b = atoi(sArr[1]);
  delay(500);

  
  
  if(a==1){
    if(b<10)//빨간불
    {
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      turn =0;
      stepper.step(turn);
     Serial.print("a : ");
     Serial.print(a);
     Serial.print(", b : ");
     Serial.println(b);
    } 
    else//초록불
    {
      {
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      turn = map(b,1,784,1,2028);
      //turn = stepsPerRev/4;
      stepper.step(turn);
      Serial.print("a : ");
     Serial.print(a);
     Serial.print(", b : ");
     Serial.println(b);
      delay(50);
      }
    }
  }
  
  stepper.step(-turn);
}

//통신은 문자열로 넘어옴
