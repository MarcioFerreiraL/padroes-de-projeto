#include <Servo.h>

const int pinoAnalogico = A0; 
const int pinoServo = 7;
const int limiar = 500; // Ajuste conforme os testes anteriores

Servo meuServo; 
int valorLido = 0;

void setup() {
  Serial.begin(9600);
  meuServo.attach(pinoServo); // Conecta o servo ao pino 9
  meuServo.write(0);          // Inicia o servo na posição 0
  
  pinMode(pinoAnalogico, INPUT);
  Serial.println("Sistema Servo-Magnetico iniciado...");
}

void loop() {
  valorLido = analogRead(pinoAnalogico);
  
  Serial.print("Valor Sensor: ");
  Serial.println(valorLido);

  // Lógica: se detectar o ímã, move o servo
  if (valorLido < limiar) { 
    meuServo.write(90); // Abre ou move para 90 graus
    Serial.println(" -> Ímã detectado: Servo em 90°");
  } else {
    meuServo.write(0);  // Volta para 0 graus
  }

  delay(100); 
}