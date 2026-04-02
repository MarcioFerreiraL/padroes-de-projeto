void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(0, HIGH);
  delay(5000);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
}
