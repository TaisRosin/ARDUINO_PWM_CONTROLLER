# ARDUINO_PWM_CONTROLLER
Controle de velocidade de motor utilizando PWM com Arduino

## Índice
1. [Introdução ao PWM](#introdução-ao-pwm)  
2. [Componentes necessários](#componentes-necessários)  
3. [Esquemático](#esquemático)  
4. [Código-fonte](#código-fonte)  
5. [Instruções de montagem](#instruções-de-montagem)  
6. [Funcionamento do projeto](#funcionamento-do-projeto)  

---

## Introdução ao PWM

PWM (Pulse Width Modulation), ou Modulação por Largura de Pulso, é uma técnica utilizada para controlar a quantidade de energia fornecida a um dispositivo eletrônico.

No caso de motores DC, o PWM permite controlar a velocidade variando o tempo em que o sinal permanece ligado (HIGH) em um determinado período.

Quanto maior o duty cycle (ciclo de trabalho), maior a velocidade do motor.

---

## Componentes necessários

- Arduino (Uno, Nano, etc.)
- Motor DC
- Botão
- Resistor (1kΩ)
- L293D

---

## 5. Instruções de montagem

1. Conecte o pino VSS (pino 16 do L293D) ao 5V do NodeMCU.  
2. Conecte o pino VS (pino 8 do L293D) ao positivo da bateria (1,5V).  
3. Conecte o GND da bateria ao GND do NodeMCU e aos pinos de GND do L293D.  
4. Conecte os pinos IN1, IN2, EN1, IN3, IN4 e EN2 do L293D aos pinos digitais do NodeMCU conforme o código.  
5. Conecte o motor DC aos pinos OUT1 (pino 3) e OUT2 (pino 6) do L293D.  
6. Conecte o diodo 1N4007 em paralelo com o motor (cátodo no positivo da bateria e ânodo no negativo do motor).  
7. Ligue a chave entre o positivo da bateria e o circuito (opcional, para ligar/desligar).  
8. Faça o upload do código para o NodeMCU.  

---

## 6. Funcionamento do projeto

Após o upload do código, o NodeMCU gera um sinal PWM no pino definido (ex: D1 ou outro configurado no código) e o driver L293D controla a energia entregue ao motor.

- Duty cycle baixo (0 – 30%): motor gira devagar  
- Duty cycle médio (30 – 70%): velocidade intermediária  
- Duty cycle alto (70 – 100%): motor gira rápido  

O controle da velocidade pode ser feito ajustando o valor do PWM no código ou recebendo entrada de um potenciômetro, botão ou via Wi-Fi.

---
