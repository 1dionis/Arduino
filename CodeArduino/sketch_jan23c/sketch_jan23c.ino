#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>

Servo myServo;

///sdsadas
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin1 = 8;
const int buttonPin2 = 13;
const int servoPin = 10;

void setup() {
pinMode(buttonPin1, INPUT_PULLUP);
myServo.attach(servoPin);
myServo.write(0);



}

void loop() {
bool button = digitalRead(buttonPin);

  servoState ^= (!button & lastButton);  // переключение по нажатию
  lastButton = button;

  myServo.write(servoState * 90);
}