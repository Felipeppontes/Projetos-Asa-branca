# Projetos-Asa-branca
Repositório destinado para os trabalhos realizados por felipe, membro da equipe de eletrônica e sistemas de telecomunicações no projeto de drones e satélites da UFPE.


Aqui está um modelo de **README** para o seu projeto no GitHub, que resume o processo completo de montagem e funcionamento.

---

# Controle de Servo Motor com Potenciômetro usando ESP32 e LM2596

Este projeto utiliza uma **ESP32** para controlar um **servo motor** com base na posição de um **potenciômetro**. A alimentação do sistema é feita através de um regulador de tensão **LM2596**, que permite utilizar uma fonte externa (9V ou 12V) para alimentar o servo e a ESP32 de forma estável.

## ⚙️ Componentes Utilizados

- 1x ESP32 DevKit
- 1x Servo motor (como SG90 ou MG995)
- 1x Potenciômetro
- 1x Módulo regulador de tensão LM2596
- 1x Fonte de alimentação (9V ou 12V)
- Fios de conexão e protoboard

## 📐 Esquema de Montagem

1. **Conexão do Regulador de Tensão LM2596**:
   - Conecte a entrada do LM2596 à **fonte externa** (9V ou 12V).
   - Ajuste a saída do LM2596 para **5V** usando um multímetro.

2. **Conexões com a ESP32 e o Servo Motor**:
   - **VOUT+ do LM2596** → **pino VIN da ESP32** (opcional) e **pino Vcc do servo**.
   - **VOUT- do LM2596** → **GND da ESP32**, **GND do servo** e **GND do potenciômetro**.
   - **Pino de controle do servo** → GPIO **32** da ESP32.
   - **Pino de sinal do potenciômetro** → GPIO **34** (pino analógico da ESP32).

3. **Conexão do Potenciômetro**:
   - Terminal esquerdo → **GND da ESP32**.
   - Terminal direito → **3.3V da ESP32**.
   - Terminal central → GPIO **34** (pino analógico da ESP32).

## 💻 Código

O código faz a leitura do valor do potenciômetro e mapeia esse valor para um ângulo entre 0° e 180°, fazendo com que o servo motor acompanhe a rotação do potenciômetro.

### Código para o projeto

```cpp
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
```

### 📋 Instruções para Uso

1. **Carregue o código na ESP32** utilizando a Arduino IDE.
2. Conecte a ESP32 ao PC para monitorar o sistema.
3. Abra o **Monitor Serial** para verificar o valor do potenciômetro e o ângulo do servo.
4. **Gire o potenciômetro** para ver o servo motor acompanhando o movimento.

## ⚠️ Considerações de Alimentação

- O **LM2596** deve estar ajustado para fornecer **5V** na saída.
- O **servo motor** e a **ESP32** compartilham o GND do regulador LM2596 para garantir uma referência comum.

---

## 📄 Licença

Este projeto está sob a licença MIT.

---

Esse README cobre o essencial para quem deseja replicar e entender o funcionamento do sistema.
