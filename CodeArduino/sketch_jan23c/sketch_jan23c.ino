#include <IRremote.h>

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(A0, ENABLE_LED_FEEDBACK); // A0 — ваш пин
  Serial.println("Ozidanie...");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("COD knopki: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX); 
    IrReceiver.resume(); 
  }
}