// Definição dos pinos
const int pinoBotao = 7;
const int pinoBuzzer = 9;

void setup() {
  // Configura os pinos de entrada e saída
  pinMode(pinoBotao, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  // Lê o estado instantâneo do botão
  int estadoBotao = digitalRead(pinoBotao);

  // Se o botão estiver pressionado
  if (estadoBotao == HIGH) {
    // Emite um som no buzzer. 
    // O formato é: tone(Pino, Frequência em Hertz)
    tone(pinoBuzzer, 1000); 
  } 
  // Se o botão estiver solto
  else {
    // Para de emitir o som imediatamente
    noTone(pinoBuzzer);     
  }
  
  // Um pequeno atraso só para estabilidade de leitura
  delay(10);
}