#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>

Servo myServo;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin1 = 8;
const int buttonPin2 = 13;
const int servoPin = 10;


bool servoState = 0;
bool lastButton = 1;

void setup() {
pinMode(buttonPin1, INPUT_PULLUP);
myServo.attach(servoPin);
myServo.write(0);
pinMode(buttonPin2, INPUT_PULLUP);
Serial.begin(9600);


}

void loop() {
  bool button = digitalRead(buttonPin1);

  servoState ^= (!button & lastButton);  // переключение по нажатию
  lastButton = button;

 myServo.write(servoState * 180);
if (digitalRead(buttonPin2) == LOW) {
    Serial.println("Кнопка нажата");
    delay(300); // чтобы не спамило
  }

}