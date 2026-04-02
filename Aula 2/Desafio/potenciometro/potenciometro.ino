void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Leitura Potenciometro: ");
  Serial.println(analogRead(A0));
  delay(1000);
}
