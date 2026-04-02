// Definição do pino
const int pinoBotao = 7;

// Variáveis de controle
int contador = 0;              // Armazena a quantidade de cliques
int estadoBotao = 0;           // Leitura atual do pino
int ultimoEstadoBotao = 0;     // Leitura da última volta do loop

// Variáveis para o debounce
unsigned long ultimoTempoDebounce = 0;
unsigned long atrasoDebounce = 50;

void setup() {
  pinMode(pinoBotao, INPUT);
  
  // Inicia a comunicação serial para exibir o contador no PC
  Serial.begin(9600);
  Serial.println("Contador de Cliques Inicializado!");
  Serial.print("Cliques: ");
  Serial.println(contador);
}

void loop() {
  // Lê o que está acontecendo no pino agora
  int leitura = digitalRead(pinoBotao);

  // Se o botão mudou de estado 
  if (leitura != ultimoEstadoBotao) {
    ultimoTempoDebounce = millis();
  }

  // Se o sinal se manteve estável por 50ms, aceitamos a mudança
  if ((millis() - ultimoTempoDebounce) > atrasoDebounce) {
    
    // Se o estado do botão realmente mudou
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      // Lógica de borda de subida: só conta quando o botão é APERTADO
      // Se quiséssemos contar na soltura, usaríamos LOW.
      if (estadoBotao == HIGH) {
        contador++;
        Serial.print("Cliques: ");
        Serial.println(contador);
      }
    }
  }

  // Salva a leitura para comparar na próxima volta do loop
  ultimoEstadoBotao = leitura;
}