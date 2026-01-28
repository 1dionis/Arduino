#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>

Servo myServo;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int photoPin = A0;
const int buttonPin2 = 13;
const int servoPin = 10;


bool servoState = 0;
bool lastLight = 0;
bool lastButton2 = HIGH;

const int lightThreshold = 500;  

void setup() {
 pinMode(buttonPin2, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(0);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

  Serial.begin(9600);


}

void loop() {
  int lightValue = analogRead(photoPin);
  bool lightState = (lightValue > lightThreshold); // 1, если свет больше порога
  // переключение состояния при изменении света
  servoState ^= (lightState & !lastLight);
  lastLight = lightState;
  myServo.write(servoState * 180);

if (digitalRead(buttonPin2) == LOW) {
    lcd.println("hdsvbdu");
    delay(300); // чтобы не спамило
  }

}