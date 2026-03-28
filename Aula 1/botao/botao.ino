// Definindo os pinos
const int pinoBotao = 8; 
const int pinoLED = 12;

// Variável para guardar o estado do botão
int estadoBotao = 0;

void setup() {
  pinMode(pinoLED, OUTPUT);    // O LED é uma saída
  pinMode(pinoBotao, INPUT);   // O botão é uma entrada
}

void loop() {
  // Lê se o botão está apertado (HIGH) ou solto (LOW)
  estadoBotao = digitalRead(pinoBotao);

  // Se o botão estiver pressionado
  if (estadoBotao == HIGH) {
    digitalWrite(pinoLED, HIGH); // Liga o LED
  } else {
    digitalWrite(pinoLED, LOW);  // Desliga o LED
  }
}