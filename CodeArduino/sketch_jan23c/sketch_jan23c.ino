#define BTN_ON 2
#define BTN_OFF 3

bool motors = false; // состояние моторчиков

void setup() {
  pinMode(BTN_ON, INPUT_PULLUP);  // кнопка ВКЛ
  pinMode(BTN_OFF, INPUT_PULLUP); // кнопка ВЫКЛ
  pinMode(LED_BUILTIN, OUTPUT);   // индикатор
}

void loop() {
  // Если нажата кнопка ВКЛ — включаем моторы
  if (digitalRead(BTN_ON) == LOW) {
    motors = true;
  }

  // Если нажата кнопка ВЫКЛ — выключаем моторы
  if (digitalRead(BTN_OFF) == LOW) {
    motors = false;
  }

  // Индикатор состояния моторчиков
  digitalWrite(LED_BUILTIN, motors ? HIGH : LOW);
}
