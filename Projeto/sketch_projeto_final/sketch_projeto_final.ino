#include <Servo.h>
#include <TM1637Display.h>

// Pinos dos Sensores
const int pinoChuva = A1;
const int pinoPotenciometro = A2;
const int pinoMagnetico = A3;

// Pinos dos Atuadores
const int pinoServoVaral = 9;
const int pinoServoPorta = 10;
const int pinoLed1 = 5;
const int pinoLed2 = 6;
const int pinoLed3 = 7;
const int pinoLed4 = 8;


// Pinos do Display TM1637
const int CLK = 12;
const int DIO = 11;

Servo servoVaral;
Servo servoPorta;
TM1637Display display(CLK, DIO);

// Variáveis para o Relógio
unsigned long tempoAnterior = 0;
int horas = 20;  
int minutos = 52; 
bool mostrarPontos = true;

// Variáveis de Controle de Energia
bool servoEmMovimento = false; 

void setup() {
  pinMode(pinoChuva, INPUT);
  pinMode(pinoMagnetico, INPUT_PULLUP); // Usando resistor interno para segurança
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT); // LED de Status Chuva
  pinMode(pinoLed4, OUTPUT); // LED de Status Porta
  display.setBrightness(0x0f);
  
  // Inicializa os servos e os coloca na posição inicial um por vez
  servoVaral.attach(pinoServoVaral);
  servoVaral.write(0);
  delay(2000); // Espera o pico de corrente passar
  servoVaral.detach(); // Desliga o sinal do servo para economizar energia

  servoPorta.attach(pinoServoPorta);
  servoPorta.write(0);
  delay(2000); 
  servoPorta.detach();
}

void loop() {
  unsigned long tempoAtual = millis();

  // 1. LÓGICA DO RELÓGIO (Atualiza a cada 1 minuto)
  if (tempoAtual - tempoAnterior >= 60000) {
    tempoAnterior = tempoAtual;
    minutos++;
    if (minutos >= 60) {
      minutos = 0;
      horas++;
      if (horas >= 24) 
        horas = 0;
    }
  }

  // Pisca os dois pontos do display a cada segundo
  mostrarPontos = (tempoAtual / 1000) % 2;
  display.showNumberDecEx(horas * 100 + minutos, (mostrarPontos ? 0x40 : 0x00), true);

  // 2. LÓGICA DOS LEDS (Dimmer via Potenciômetro)
  int valorPot = analogRead(pinoPotenciometro);
  int brilho = map(valorPot, 0, 1023, 0, 255);
  analogWrite(pinoLed1, brilho);
  analogWrite(pinoLed2, brilho);

  // 3. LÓGICA DO VARAL (Prioridade 1)
  int leituraChuva = analogRead(pinoChuva);
  if (leituraChuva < 500 && !servoEmMovimento) { 
    moverServoVaral(90); // Fecha o varal
    digitalWrite(pinoLed3, LOW);
  } else if (leituraChuva >= 500 && !servoEmMovimento) {
    moverServoVaral(0);  // Abre o varal
    digitalWrite(pinoLed3, HIGH);

  }

  // 4. LÓGICA DA PORTA (Prioridade 2 - Só move se o varal estiver parado)
  int leituraSensorMagnetico = analogRead(pinoMagnetico);
  if (leituraSensorMagnetico < 800 && !servoEmMovimento) {
    moverServoPorta(90); 
    digitalWrite(pinoLed4, LOW);

  } else if (leituraSensorMagnetico >= 800 && !servoEmMovimento) {
    moverServoPorta(0); 
    digitalWrite(pinoLed4, HIGH);

  }
}

// Funções para mover servos com proteção de corrente
void moverServoVaral(int angulo) {
  static int anguloAtual = -1;
  if (angulo == anguloAtual) return;

  servoEmMovimento = true;
  servoVaral.attach(pinoServoVaral);
  servoVaral.write(angulo);
  delay(1000); // Tempo para o movimento físico terminar
  servoVaral.detach(); // "Corta" a energia do motor
  servoEmMovimento = false;
  anguloAtual = angulo;
  delay(500); // Intervalo de respiro para a fonte
}

void moverServoPorta(int angulo) {
  static int anguloAtual = -1;
  if (angulo == anguloAtual) return;

  servoEmMovimento = true;
  servoPorta.attach(pinoServoPorta);
  servoPorta.write(angulo);
  delay(1000);
  servoPorta.detach();
  servoEmMovimento = false;
  anguloAtual = angulo;
  delay(500);
}