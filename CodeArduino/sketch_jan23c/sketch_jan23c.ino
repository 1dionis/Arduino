#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>

Servo myServo;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin1 = 8;
const int buttonPin2 = 13;
const int servoPin = 10;

void setup() {
pinMode(buttonPin1, INPUT_PULLUP);
myservo.attach(servoPin1);




}

void loop() {
myServo.write(digitalRead(buttonPin)*180);

}