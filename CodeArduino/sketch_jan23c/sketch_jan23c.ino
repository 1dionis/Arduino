#define BTN_ON  7
#define BTN_OFF 8

bool motors = false;

void setup() {
  pinMode(BTN_ON, INPUT_PULLUP);
  pinMode(BTN_OFF, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT); // в качестве индикатора работы
}

void loop() {
  if (digitalRead(BTN_ON) == LOW) motors = true;
  if (digitalRead(BTN_OFF) == LOW) motors = false;

  if (motors) {
    digitalWrite(LED_BUILTIN, HIGH); // имитация включения моторчиков
  } else {
    digitalWrite(LED_BUILTIN, LOW);  // имитация выключения
  }
}