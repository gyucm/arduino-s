#include <SPI.h> //SPIcard
#include <MFRC522.h> //rc522

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:
  SPI.begin(); //SPI 통신 활용
  mfrc.PCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mfrc.PICC_IsNewCardPresent())
  return;
  if(!mfrc.PICC_ReadCardSerial())
  return;

  /*if(mfrc.uid.uidByte[0]==201&& //UI를 통해 카드 태그시 실행문
    mfrc.uid.uidByte[1]==432&&
    mfrc.uid.uidByte[2]==226&&
    mfrc.uid.uidByte[3]==184)
    {
      Serial.println("Authorized access");
      delay(500);
    }
    else
    Serial.println("Authorized denied");
*/
  Serial.print("card UID : "); //카드 UI값 확인
  for(byte i = 0; i<4; i++){
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}
