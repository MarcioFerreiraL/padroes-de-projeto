int Led1 = 9;
int Led2 = 10;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() {
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, LOW);
  delay(2000);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  delay(2000);
  
}
