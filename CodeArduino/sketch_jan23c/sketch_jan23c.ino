void setup() {
  pinMode(5, OUTPUT); // ENA
  pinMode(6, OUTPUT); // IN1
  pinMode(7, OUTPUT); // IN2

  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  analogWrite(5, 200);
}

void loop() {
}