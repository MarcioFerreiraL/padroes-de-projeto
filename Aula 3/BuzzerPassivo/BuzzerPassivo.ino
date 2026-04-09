#define KY006 5

void setup() {
  pinMode(KY006, OUTPUT);
}

void loop() {
  // Faz o som subir de frequência (tom)
 // for (int freq = 200; freq < 2000; freq += 10) {
    tone(KY006, 1000); 
  //  delay(20); 
  //}
  delay(10000);
  noTone(KY006); // Desliga o som
  delay(2000);   // Espera 2 segundos antes de recomeçar
}