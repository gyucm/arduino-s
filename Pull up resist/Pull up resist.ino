//풀업
volatile byte state = HIGH; //volatile 뭔지 모름 질문필요

void isr()
{
  //static int count = 0;
  //Serial.println(count++);
  digitalWrite(13,state);
  state = !state;
}

 void setup() {
  attachInterrupt(1, isr, FALLING);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
 
}