void setup() {
 Serial.begin(9600); 
 pinMode(13, OUTPUT); //내장 램프 점등
}

void loop() {
  int data = Serial.read(); //수신
  Serial.println(data); 
  if(data == 'a')
  {
    digitalWrite(13, HIGH);
  }
  else if (data == 'b') //b 입력시 출력
{
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
}
  else
  {
    digitalWrite(13, LOW);
  }
  //Serial.println(Serial.read());에코(내가 친게 다시 나에게 돌아옴)
}