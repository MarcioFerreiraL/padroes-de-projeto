#include <TM1637Display.h>

// Definição dos pinos de conexão
const int CLK = 2;
const int DIO = 3;

// Inicializa o objeto do display
TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(0x0f); // Ajusta o brilho para o máximo (0 a 15 ou 0x0f)
  display.clear();             // Limpa o display
}

void loop() {
  // Loop de 0 a 9999
  for (int i = 0; i <= 9999; i++) {
    // showNumberDec(número, zeros_à_esquerda, comprimento, posição)
    display.showNumberDec(i, false); 
    
    delay(1000); // Velocidade do contador (100ms)
  }
  
  delay(2000); // Pausa antes de reiniciar
}