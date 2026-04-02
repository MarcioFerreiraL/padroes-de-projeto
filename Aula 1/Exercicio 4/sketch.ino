const int pinoSensor = A0;  // Pino analógico

// Variáveis para controlar o tempo
unsigned long tempoAnterior = 0;  
const long intervalo = 1000;      // Intervalo de 1 segundo

void setup() {
  // Inicia a comunicação com o computador a 9600 bps
  Serial.begin(9600);
  Serial.println("Iniciando monitoramento de temperatura...");
}

void loop() {
  // Pega o tempo atual de execução do Arduino
  unsigned long tempoAtual = millis();

  // Verifica se já passou 1 segundo desde a última leitura
  if (tempoAtual - tempoAnterior >= intervalo) {
    // Salva o tempo atual para a próxima contagem
    tempoAnterior = tempoAtual;

    // 1. Lê o valor bruto do sensor
    int leituraBruta = analogRead(pinoSensor);

    // 2. Transforma o valor bruto em Celsius
    const float BETA = 3950;
    float temperaturaC = 1 / (log(1 / (1023. / leituraBruta - 1)) / BETA + 1.0 / 298.15) - 273.15;

    // Mostra o resultado no Serial Monitor
    Serial.print("Temperatura atual: ");
    Serial.print(temperaturaC);
    Serial.println(" *C");
  }
}