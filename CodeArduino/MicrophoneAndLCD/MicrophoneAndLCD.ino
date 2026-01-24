#include <LiquidCrystal.h>

// Инициализируем библиотеку с номерами пинов интерфейса
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int micPin = A0; 
int threshold = 30; // Порог чувствительности (разница от среднего значения)

void setup() {
  lcd.begin(16, 2); // Указываем размер экрана
  lcd.setCursor(0, 0);
  lcd.print("Monitor zvuka:");
}

void loop() {
  // Читаем значение с микрофона
  int sensorValue = analogRead(micPin);
  
  // Большинство таких модулей в тишине выдают около 512 (половина от 1023)
  // Считаем модуль отклонения от "тихого" центра
  int amplitude = abs(sensorValue - 512); 

  lcd.setCursor(0, 1);
  
  if (amplitude > threshold) {
    lcd.print("Slyshno!        "); 
  } else {
    lcd.print("Polnaya tishina ");
  }

  delay(100); 
}