#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 9
#define RST_PIN 10

Servo myServo;
MFRC522 mfrc522(SS_PIN, RST_PIN);

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int buttonPin2 = A0;
const int servoPin = 8;

bool servoState = 0;
bool lastCardState = 0;
bool lastButton2 = HIGH;

// UID карты (замени на свой)
byte allowedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  pinMode(buttonPin2, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(0);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {

  // ===== RFID вместо фоторезистора =====
  bool cardPresent = false;

  if (mfrc522.PICC_IsNewCardPresent() &&
      mfrc522.PICC_ReadCardSerial()) {

    cardPresent = true;

    bool uidMatch = true;
    for (byte i = 0; i < 4; i++) {
      if (mfrc522.uid.uidByte[i] != allowedUID[i]) {
        uidMatch = false;
        break;
      }
    }

    if (uidMatch) {
      servoState ^= (cardPresent & !lastCardState);
      myServo.write(servoState * 180);
      delay(700);
      myServo.write(0);
    }

    mfrc522.PICC_HaltA();
  }

  lastCardState = cardPresent;

  // ===== КНОПКА =====
  if (digitalRead(buttonPin2) == LOW && lastButton2 == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Button pressed");
    delay(300);
  }

  lastButton2 = digitalRead(buttonPin2);
}