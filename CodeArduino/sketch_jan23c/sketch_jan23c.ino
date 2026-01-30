// ===== КНОПКИ =====
const int buttonOn  = 7;
const int buttonOff = 8;

// ===== МОЩНОСТЬ МОТОРОВ (0 - 255) =====
int motorPower = 150;   // ← МЕНЯЙ ЗДЕСЬ СКОРОСТЬ

// ===== МОТОРЫ =====
int EN[] = {5, 9, 10, 11};     // PWM пины
int IN1[] = {6, 8, 12, A0};
int IN2[] = {7, 10, 13, A1};

bool motorsOn = false;

void setup() {
  pinMode(buttonOn, INPUT_PULLUP);
  pinMode(buttonOff, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(EN[i], OUTPUT);
    pinMode(IN1[i], OUTPUT);
    pinMode(IN2[i], OUTPUT);
  }
}

void loop() {
  if (digitalRead(buttonOn) == LOW) {
    motorsOn = true;
  }

  if (digitalRead(buttonOff) == LOW) {
    motorsOn = false;
  }

  if (motorsOn) {
    turnMotorsOn();
  } else {
    turnMotorsOff();
  }
}

void turnMotorsOn() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(IN1[i], HIGH);
    digitalWrite(IN2[i], LOW);
    analogWrite(EN[i], motorPower);
  }
}

void turnMotorsOff() {
  for (int i = 0; i < 4; i++) {
    analogWrite(EN[i], 0);
  }
}