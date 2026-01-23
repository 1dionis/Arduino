#include <LiquidCrystal.h>
#include <Keypad.h>

// Дисплей: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int resetPin = 13; 

// Настройка клавиатуры
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; 
byte colPins[COLS] = {10, 9, 8, 7}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(resetPin, INPUT_PULLUP); // Пин 13 на вход с подтяжкой
  
  lcd.begin(16, 2);
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
  lcd.print("Enter code:");
  lcd.setCursor(0, 1); 
}

void loop() {
  char key = keypad.getKey();

  // Обработка клавиш
  if (key) {
    lcd.print(key);
  }

  // Обработка кнопки очистки (пин 13)
  if (digitalRead(resetPin) == LOW) { 
    // Если светодиод L гаснет, значит мы здесь!
    
    lcd.setCursor(0, 1);
    lcd.print("CLEARED!        "); // Визуальное подтверждение
    delay(500);                   // Задержка, чтобы вы успели увидеть
    
    lcd.setCursor(0, 1);
    lcd.print("                "); // Очищаем строку пробелами
    lcd.setCursor(0, 1);           // Ставим курсор в начало для нового ввода
    
    while(digitalRead(resetPin) == LOW); // Ждем, пока отпустите кнопку
  }
}