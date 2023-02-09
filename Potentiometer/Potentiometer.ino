int LED = 3;

void setup() {
  pinMode(A5, INPUT);
 pinMode(LED, OUTPUT);
 Serial.begin(9600); 
}

void loop() {
  int data = analogRead(A5); //가변저항 데이터값 받기
  data = map(data, 0, 1023, 0, 255);
  Serial.println(data);
  delay(100);
  analogWrite(LED,data); // 숫자가 크므로 조절
}