#include <IRremote.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); // Принудительно гасим L
  
  Serial.begin(9600);
  // Инициализируем приемник на пине A0 БЕЗ светодиодной индикации
  IrReceiver.begin(A0, DISABLE_LED_FEEDBACK); 
  Serial.println("Система очищена. Жду пульт на A0...");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("УРА! Код получен: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    // Мгновенно мигнем светодиодом L только при получении сигнала
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    `
    IrReceiver.resume(); 
  }
}