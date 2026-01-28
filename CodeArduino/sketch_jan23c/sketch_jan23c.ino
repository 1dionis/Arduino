#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>

Servo myServo;


LiquidCrystal lcd(12, 5, 4, 3, 2);
const int buttonPin1 = 8;
const int buttonPin2 = 13;
const int servoPin = 10;

void setup() {
pinMode(buttonPin, INPUT_PULLUP);
myservo.attach(servoPin1);




}

void loop() {
myServo.write(digitalRead(buttonPin)*180);

}