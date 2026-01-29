#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>
#include <IRremote.h>   // ← добавлено

Servo myServo;

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
const int irPin = A0;        // ← БЫЛ photoPin
const int buttonPin2 = 9;
const int servoPin = 8;

bool servoState = 0;
bool lastIR = 0;
bool lastButton2 = HIGH;

// ===== ИК-приёмник =====
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  pinMode(buttonPin2, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(0);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

  Serial.begin(9600);

  irrecv.enableIRIn();   // ← запуск ИК
}

void loop() {

  // ===== ИК ПУЛЬТ (вместо фоторезистора) =====
  bool irState = false;

  if (irrecv.decode(&results)) {
    irState = true;          // кнопка нажата
    irrecv.resume();         // готов к следующему сигналу
  }

  servoState ^= (irState & !lastIR);
  lastIR = irState;
  myServo.write(servoState * 180);

  // ===== КНОПКА =====
  if (digitalRead(buttonPin2) == HIGH) {
    lcd.println("hdsvbdu");
    delay(300);
  }
}