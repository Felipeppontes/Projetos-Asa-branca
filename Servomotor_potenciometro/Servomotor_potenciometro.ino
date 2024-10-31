#include <ESP32Servo.h>  // Biblioteca compatível com ESP32

// Definição dos pinos
static const int servoPin = 32;  // Pino de controle do servo
static const int potPin = 34;    // Pino analógico para o potenciômetro

Servo servo1;  // Objeto servo

void setup() {
  Serial.begin(115200);          // Inicializa a comunicação serial
  servo1.attach(servoPin);        // Conecta o servo ao pino especificado
}

void loop() {
  // Lê o valor do potenciômetro (0 a 4095)
  int potValue = analogRead(potPin);  

  // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
  int angle = map(potValue, 0, 4095, 0, 180);

  // Move o servo para o ângulo correspondente
  servo1.write(angle);

  // Exibe o valor no Monitor Serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValue);
  Serial.print(" -> Ângulo: ");
  Serial.println(angle);

  delay(15);  // Pequeno atraso para suavizar o movimento
}
