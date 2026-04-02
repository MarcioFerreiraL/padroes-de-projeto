const int buttonPin = 7;    // Pino onde o botão está conectado
const int ledPin = 8;       // Pino onde o LED está conectado

int ledState = LOW;         // Estado atual do LED
int buttonState;            // Leitura atual do botão
int lastButtonState = LOW;  // Leitura anterior do botão

unsigned long lastDebounceTime = 0;  // Último momento em que o pino mudou de estado
unsigned long debounceDelay = 50;    // Tempo de debounce

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Define o estado inicial do LED para garantir que comece desligado
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Lê o estado atual do botão
  int reading = digitalRead(buttonPin);

  // Se o estado mudou, reseta o temporizador
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Se a leitura se manteve estável pelo tempo de debounce definido
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    // Se o estado do botão realmente mudou
    if (reading != buttonState) {
      buttonState = reading;

      // Só alterna o LED se o novo estado do botão for HIGH
      if (buttonState == HIGH) {
        ledState = !ledState; // Inverte o estado atual do LED
      }
    }
  }

  // Aplica o estado atualizado ao LED
  digitalWrite(ledPin, ledState);

  // Salva a leitura atual para a próxima volta do loop
  lastButtonState = reading;
}