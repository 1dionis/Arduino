#include <LiquidCrystal.h>
#include <Keypad.h>

// 1. Настройка дисплея (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 2. Настройка клавиатуры
const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Пины строк подключаем к аналоговым входам
byte rowPins[ROWS] = {A0, A1, A2, A3}; 
// Пины столбцов к оставшимся цифровым
byte colPins[COLS] = {10, 9, 8, 7}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);      // Инициализация дисплея 16x2
  lcd.print("Enter code:");
  lcd.setCursor(0, 1);   // Переход на вторую строку
}

void loop() {
  char key = keypad.getKey(); // Опрос кнопок

  if (key) {
    lcd.print(key); // Выводим нажатый символ
  }
}