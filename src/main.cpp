#include <Arduino.h>

const int pinoMotor = 9;   // Pino PWM para o motor
const int pinoBotao = 2;   // Pino D2 para o botão
int nivelVelocidade = 1;   // Começa no primeiro nível (64)

void setup() {
  pinMode(pinoMotor, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP); // Usa o resistor interno para manter o pino em HIGH
  
  // Inicia com a velocidade mínima definida
  analogWrite(pinoMotor, 64);
}

void loop() {
  // Verifica se o botão foi pressionado (LOW porque usamos INPUT_PULLUP)
  if (digitalRead(pinoBotao) == LOW) {
    delay(50); // Debounce simples
    
    // Espera soltar o botão para não ficar incrementando sem parar
    while(digitalRead(pinoBotao) == LOW);
    
    nivelVelocidade++;

    // Reinicia o ciclo se passar do nível 4
    if (nivelVelocidade > 4) {
      nivelVelocidade = 1;
    }

    // Aplica a velocidade baseada no nível atual
    switch (nivelVelocidade) {
      case 1:
        analogWrite(pinoMotor, 64);
        break;
      case 2:
        analogWrite(pinoMotor, 128);
        break;
      case 3:
        analogWrite(pinoMotor, 192);
        break;
      case 4:
        analogWrite(pinoMotor, 256);
        break;
    }
    
    delay(50); // Pequena pausa para estabilidade
  }
}