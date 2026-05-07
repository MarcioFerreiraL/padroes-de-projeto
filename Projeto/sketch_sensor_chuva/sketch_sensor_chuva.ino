#include <Servo.h>

Servo meuServo;          // Cria o objeto para controlar o servo
const int pinoSensor = A0; // Pino do sensor de chuva
int limiteChuva = 800;   // Ajuste este valor conforme a necessidade

void setup() {
  meuServo.attach(9);    // Conecta o servo ao pino digital 9
  meuServo.write(0);     // Inicia o servo na posição 0 graus (Aberto)
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoSensor);
  Serial.print("Leitura do Sensor: ");
  Serial.println(leitura);

  if (leitura < limiteChuva) {
    // Se detectar chuva, fecha a janela/toldo
    Serial.println("Chuva detectada! Fechando...");
    meuServo.write(90);  // Gira o servo para 90 graus
  } else {
    // Se parar de chover, abre novamente
    Serial.println("Tempo seco. Abrindo...");
    meuServo.write(0);   // Retorna o servo para 0 graus
  }

  delay(1000); // Aguarda 1 segundo para evitar movimentos bruscos
}