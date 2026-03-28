const int pinoLDR = A0; // Pino onde o LDR está conectado
int valorLDR = 0;       // Variável para armazenar a leitura

void setup() {
  Serial.begin(9600);   // Inicia a comunicação com o computador
  pinMode(pinoLDR, INPUT);
}

void loop() {
  valorLDR = analogRead(pinoLDR); // Lê o valor de 0 a 1023
  
  Serial.print("Luminosidade: ");
  Serial.println(valorLDR); // Mostra o valor no monitor
  
  delay(500); // Espera meio segundo para a próxima leitura
}