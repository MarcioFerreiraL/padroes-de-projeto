#include <TM1637Display.h>

// Definições dos pinos
const int CLK = 2;
const int DIO = 3;
const int pinoPot = A1;
const int pinoBuzzer = 8;

// Inicializa o display
TM1637Display display(CLK, DIO);

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  display.setBrightness(0x0f); // Brilho máximo
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoPot);
  
  // Mapeia a leitura (0-1023) para uma escala de 0 a 100%
  int porcentagem = map(leitura, 0, 1023, 0, 100);
  
  // Mostra o valor no display
  display.showNumberDec(porcentagem);

  // Lógica do Buzzer: se passar de 90%, ele dá um aviso sonoro
  if (porcentagem > 90) {
    digitalWrite(pinoBuzzer, HIGH);
    delay(20); // Bipe bem curto
    digitalWrite(pinoBuzzer, LOW);
  }

  // Debug no Monitor Serial
  Serial.print("Valor: ");
  Serial.println(porcentagem);

  delay(100); // Pequeno delay para estabilizar o display
}