#define led 13
boolean state = false;
unsigned long pre_time =0;
unsigned long cur_time;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cur_time = millis();
  if(cur_time - pre_time >= 500)
  {
    pre_time = cur_time;
    state = !state;
    digitalWrite(led,state);
  }
}
