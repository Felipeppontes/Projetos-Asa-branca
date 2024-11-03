#include <ESP32Servo.h>  // Biblioteca compatível com ESP32


// ----------------Definição dos pinos de controle dos servos:------------------------
static const int servoPin1 = 25;  // Pino de controle do servo
static const int servoPin2 = 26;  // Pino de controle do servo
static const int servoPin3 = 27;  // Pino de controle do servo
//-----------------sinal de controle dos potenciômetros--------------------------------
static const int potPin1 = 35;    // Pino analógico para o potenciômetro
static const int potPin2 = 32;    // Pino analógico para o potenciômetro
static const int potPin3 = 33;    // Pino analógico para o potenciômetro

// Objetos servo:
Servo servo1;  
Servo servo2;  
Servo servo3;  

void setup() {
  Serial.begin(115200);          // Inicializa a comunicação serial
  //servo1.attach(servoPin1);        // Conecta o servo ao pino especificado
  //servo1.attach(servoPin2);
  //servo1.attach(servoPin3);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
}

void loop() {
  if(analogRead(potPin1)!= 0){  // Lê o valor do potenciômetro (0 a 4095)
  int potValue = analogRead(potPin1);  

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
  if(analogRead(potPin2)!= 0){

      // Lê o valor do potenciômetro (0 a 4095)
  int potValue = analogRead(potPin2);  

  // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
  int angle = map(potValue, 0, 4095, 0, 180);

  // Move o servo para o ângulo correspondente
  servo2.write(angle);

  // Exibe o valor no Monitor Serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValue);
  Serial.print(" -> Ângulo: ");
  Serial.println(angle);

  delay(15);  // Pequeno atraso para suavizar o movimento
  }
  if(analogRead(potPin3) > 0){
      // Lê o valor do potenciômetro (0 a 4095)
  int potValue = analogRead(potPin3);  

  // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
  int angle = map(potValue, 0, 4095, 0, 180);


  // Move o servo para o ângulo correspondente
  servo3.write(angle);

  // Exibe o valor no Monitor Serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValue);
  Serial.print(" -> Ângulo: ");
  Serial.println(angle);

  delay(15);  // Pequeno atraso para suavizar o movimento
  }
}
