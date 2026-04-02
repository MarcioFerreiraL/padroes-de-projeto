const int ldrPin = A0;   // Pino analógico onde o LDR está conectado
const int ledPin = 8;    // Pino digital onde o LED está conectado

// Variável para definir o ponto de transição 
const int limiteLuz = 400; 

void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  
  // Inicia a comunicação para monitorar os valores do LDR
  Serial.begin(9600);
}

void loop() {
  // Lê o valor analógico do LDR
  int valorLDR = analogRead(ldrPin);

  // Mostra o valor no Monitor Serial para ajudar na calibração
  Serial.print("Leitura do Sensor LDR: ");
  Serial.println(valorLDR);

  // Se o valor lido for MENOR que o limite, significa que está ESCURO.
  if (valorLDR < limiteLuz) {
    digitalWrite(ledPin, HIGH);  // Acende o LED
  } 
  // Se for MAIOR ou IGUAL ao limite, está CLARO.
  else {
    digitalWrite(ledPin, LOW);   // Apaga o LED
  }
  delay(500);
}