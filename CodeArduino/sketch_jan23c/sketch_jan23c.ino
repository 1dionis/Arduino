#include <SPI.h>
#include <MFRC522.h>

// Ваши пины согласно предыдущей схеме
#define RST_PIN         7          
#define SS_PIN          10         

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Создаем объект модуля

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println(F("--- Тест связи с RC522 ---"));
  
  // Выполняем самодиагностику
  mfrc522.PCD_DumpVersionToSerial(); 
}

void loop() {
  // Проверка: поднесена ли новая карта?
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Проверка: можно ли считать данные с карты?
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Если мы здесь — карта обнаружена!
  Serial.print(F("Ура! Ключ обнаружен. UID карты:"));

  // Выводим UID в шестнадцатеричном формате
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  
  Serial.println();
  Serial.println(F("------------------------------------"));

  // Остановка чтения (чтобы не дублировать вывод одной и той же карты)
  mfrc522.PICC_HaltA();
}