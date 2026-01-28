#include <Servo.h>

Servo myServo;

const int buttonPin = 8;
const int servoPin  = 10;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // кнопка на GND
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(digitalRead(buttonPin) * 90);
}