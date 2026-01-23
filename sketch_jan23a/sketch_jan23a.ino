#include <Servo.h> // подключаем библиотеку для работы с сервоприводом
Servo servo; // объявляем переменную servo типа "servo"
int led_pinGreen=3;        // пин подключения
int led_pinRed=6;
int button_pin = 2;     // пин кнопки
// переменные
int buttonState = 0;          // переменная для хранения состояния кнопки
void setup() { 
    pinMode(led_pinGreen, OUTPUT); // Инициализируем цифровой вход/выход в режиме выхода.
    pinMode(button_pin, INPUT); // Инициализируем цифровой вход/выход в режиме входа.
    servo.attach(5); // привязываем сервопривод к аналоговому выходу 10
}
void loop() {
  buttonState = digitalRead(button_pin);// считываем значения с входа кнопки
   if (buttonState == HIGH) { 
    digitalWrite(led_pinGreen, HIGH);// зажигаем светодиод
    digitalWrite(led_pinRed, LOW);
    servo.write(0); //ставим вал на 180
    delay (1000); // задержка в 1 секунду
  }
  else {
    digitalWrite(led_pinRed, HIGH);
    digitalWrite(led_pinGreen, LOW);// выключаем светодиод
    servo.write(180); //ставим вал на 0
    delay (1000); // задержка в 1 секунду
  }
}
