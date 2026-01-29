#include <AccelStepper.h>
#include <Servo.h>
#include <LedControl.h>
#include <LiquidCrystal.h>
#include <IRremote.h>

Servo myServo;

LiquidCrystal lcd(7, 6 , 5, 4, 3, 2);
const int irPin = A0;
const int buttonPin2 = 9;
const int servoPin = 8;


bool servoState = 0;
bool lastLight = 0;
bool lastButton2 = HIGH;

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

irrecv.enableIRIn();
}

void loop() {
  bool irState = false;

  if(irrecv.decode(&results)){
irState = true;
irrecv.recume();
  }

servoState ^= (irState & !lastIR);
lastrIR = irState;
myServo.write(servoState * 180);

if (digitalRead(buttonPin2) == HIGH) {
    lcd.println("hdsvbdu");
    delay(300); // чтобы не спамило
  }

}