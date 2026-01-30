#define BTN_ON  2
#define BTN_OFF 3

bool motors = false;

void setup() {
  pinMode(BTN_ON, INPUT_PULLUP);
  pinMode(BTN_OFF, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT); // встроенный светодиод для проверки
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // проверяем кнопку ВКЛ
  if (digitalRead(BTN_ON) == LOW) {
    motors = true;
    delay(200); // небольшая задержка, чтобы кнопка не «дребезжала»
  }

  // проверяем кнопку ВЫКЛ
  if (digitalRead(BTN_OFF) == LOW) {
    motors = false;
    delay(200); // небольшая задержка
  }

  // включаем или выключаем LED по состоянию
  if (motors) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
