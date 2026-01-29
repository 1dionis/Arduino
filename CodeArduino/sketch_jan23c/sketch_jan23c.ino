#include <IRremote.h>

void setup() {
  Serial.begin(9600);
  // Пробуем инициализацию на 11 пине
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK); 
  Serial.println("Система запущена. Жду сигнал...");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("УРА! Поймал код: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();
  }
}