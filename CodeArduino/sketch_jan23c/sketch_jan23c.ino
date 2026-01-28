#include <LiquidCrystal.h>

// Инициализация экрана
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0; // Пин фоторезистора
int sensorValue = 0;      // Переменная для хранения данных
int threshold = 150;      // Порог (настрой под свой свет)

void setup() {
  lcd.begin(16, 2);
  lcd.print("Light Test:");
  delay(1000);
}

void loop() {
  sensorValue = analogRead(sensorPin); // Читаем значение от 0 до 1023

  lcd.clear();
  lcd.setCursor(0, 0);
  
  // Выводим цифровое значение для настройки
  lcd.print("Val: ");
  lcd.print(sensorValue);

  lcd.setCursor(0, 1);
  if (sensorValue > threshold) {
    lcd.print("LIGHT ON (Svetit)");
  } else {
    lcd.print("DARK (Ne svetit)");
  }

  delay(300); // Чтобы текст не мелькал слишком быстро
}