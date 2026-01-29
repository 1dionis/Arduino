#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Настройки пинов
#define RST_PIN         9          
#define SS_PIN          10         
#define BUTTON_PIN      A0
#define SERVO_PIN       8

// Углы поворота серво (подберите под свою конструкцию)
#define SERVO_IDLE      0    // Исходное положение
#define SERVO_PRESS     45   // Положение при нажатии кнопки

MFRC522 mfrc522(SS_PIN, RST_PIN);  
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo myServo;

void setup() {
  Serial.begin(9600);
  SPI.begin();           
  mfrc522.PCD_Init();    
  
  lcd.begin(16, 2);
  lcd.print("Ready...");

  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_IDLE); // Ставим серво в исходное

  // Кнопку подключаем с внутренней подтяжкой (INPUT_PULLUP)
  // При нажатии на кнопку на пине будет LOW (0)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Сначала проверяем нажатие кнопки (нажал ли её сервопривод)
  if (digitalRead(BUTTON_PIN) == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Button Pressed!");
    lcd.setCursor(0, 1);
    lcd.print("Access Granted");
    delay(2000); // Ждем 2 секунды
    lcd.clear();
    lcd.print("Ready...");
  }

  // Проверка RFID метки
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Если карта поднесена - двигаем сервопривод
  lcd.clear();
  lcd.print("Card Detected!");
  
  myServo.write(SERVO_PRESS); // Серво нажимает на кнопку
  delay(1000);                // Держим секунду
  myServo.write(SERVO_IDLE);  // Возвращаем серво назад
  
  mfrc522.PICC_HaltA();       // Останавливаем чтение карты
}