#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>

LiquidCrystal lcd(12, 5, 4, 3, 2);
const int buttonPin1 = 8;
const int buttonPin2 = 13;
const int servoPin = 10;

void setup() {
myservo.attach(servoPin);
pinMode(buttonPin, INPUT_PULLUP);




}

void loop() {
myServo.write(digitalRead(buttonPin);

}