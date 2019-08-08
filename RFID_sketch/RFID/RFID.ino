// Wire it according to: http://www.arduinotutorialonline.com/2018/06/arduino-mega2560-rfid-rc522-arduino.html
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 53
#define RST_PIN 49
#define servoPin 9
int servoAngle;
Servo servo;

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  SPI.begin();       // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  Serial.println("RFID reading UID");
}
void loop() {
  if ( mfrc522.PICC_IsNewCardPresent())
  {
    if ( mfrc522.PICC_ReadCardSerial())
    {
      Serial.print("Tag UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }

      Serial.println();
      mfrc522.PICC_HaltA();
      Unlock();
      delay(2000);
      Lock();
    }
  }
}

void Unlock() {
  for (servoAngle = 0; servoAngle < 180; servoAngle++) //move the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    delay(50);
  }
}


void Lock() {
  for (servoAngle = 180; servoAngle > 0; servoAngle--) //now move back the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    delay(10);
  }
}
