// 인터럽트제거 
volatile byte state = HIGH;
unsigned long pre_time =0;
unsigned long cur_time =0;

void isr()
{
  static int count = 0;
  cur_time = millis(); // 채터링 현상 보수
  if(cur_time - pre_time >= 500)
  {
    Serial.println(count++);
    pre_time = cur_time;
  }
}
void setup() {
  Serial.begin(9600);
   //attachInterrupt(1, isr, FALLING);
  Mstimer2::set()
}

void loop() {
  
}

volatile byte state = HIGH;

void isr()
{
  static int count = 0;
  Serial.println(count++);
   
}
void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000, isr);
  MsTimer2::start();
}

void loop() {
}