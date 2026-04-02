const int buttonPin1 = 9; 
const int buttonPin2 = 10;
const int buttonPin3 = 11;
const int ledPin1 = 3;    
const int ledPin2 = 4;

int ledState1 = LOW;
int ledState2 = HIGH;
int buttonState1;  
int buttonState2;
int buttonState3;              // Leitura atual do botão
int lastButtonState1 = LOW;
int lastButtonState2 = LOW; 
int lastButtonState3 = LOW;   // Leitura anterior do botão

unsigned long lastDebounceTime = 0;  // Último momento em que o pino mudou de estado
unsigned long debounceDelay = 50;    // Tempo de debounce

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Define o estado inicial do LED para garantir que comece desligado
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
}

void loop() {
  // Lê o estado atual do botão
  int reading = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);

  // Se o estado mudou, reseta o temporizador
  if (reading != lastButtonState1 || reading2 != lastButtonState2 || reading3 != lastButtonState3) {
    lastDebounceTime = millis();
  }

  // Se a leitura se manteve estável pelo tempo de debounce definido
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    // Se o estado do botão realmente mudou
    if (reading != buttonState1) {
      buttonState1 = reading;

      // Só alterna o LED se o novo estado do botão for HIGH
      if (buttonState1 == HIGH) {
        ledState1 = !ledState1; // Inverte o estado atual do LED
      }
    }

    if (reading2 != buttonState2) {
      buttonState2 = reading2;

      // Só alterna o LED se o novo estado do botão for HIGH
      if (buttonState2 == HIGH) {
        ledState2 = !ledState2; // Inverte o estado atual do LED
      }
    }

    if (reading3 != buttonState3) {
      buttonState3 = reading3;

      // Só alterna o LED se o novo estado do botão for HIGH
      if (buttonState3 == HIGH) {
        ledState1 = !ledState1; // Inverte o estado atual do LED
        ledState2 = !ledState2;
      }
    }

    
  }

  // Aplica o estado atualizado ao LED
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  

  // Salva a leitura atual para a próxima volta do loop
  lastButtonState1 = reading;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
  
}