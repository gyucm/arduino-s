int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
}

void loop() {
 
  int remote = 0;
  if(irrecv.decode(&results))
  {
    remote = results.value;
    Serial.println(remote);
    irrecv.resume();
    if(remote == 26775)
    digitalWrite(13, HIGH);
    else if(remote == -26521);
    digitalWrite(13, LOW);
  }
  delay(100);
}