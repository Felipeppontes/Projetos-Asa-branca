# Projetos-Asa-branca
Repositório destinado para os trabalhos realizados por felipe, membro da equipe de eletrônica e sistemas de telecomunicações no projeto de drones e satélites da UFPE.

Aqui está um modelo de **README** para resumir o objetivo geral do projeto de construção de um **braço robótico** com **quatro servos** utilizando **ESP32**, alimentação externa e um regulador **LM2596**.

---

# Braço Robótico com ESP32

## 🎯 Objetivo Geral do Projeto

O objetivo deste projeto é construir um **braço robótico** controlado por **quatro servo motores**, utilizando uma **ESP32** como unidade de controle. O sistema será alimentado por células de **3,7V** conectadas a um regulador de tensão **LM2596**, que garantirá uma tensão estável para os servos e para a ESP32.

## 📐 Componentes Utilizados

- 1x ESP32
- 4x Servo motores (como SG90 ou MG995)
- 1x Regulador de tensão LM2596
- 2x Células de 3,7V (Li-ion ou LiPo)
- 1x Placa de montagem para o braço robótico
- Fios de conexão e protoboard

## ⚙️ Montagem do Braço Robótico

1. **Estrutura do Braço**:
   - Siga as instruções do manual de montagem disponível em [Braço Robótico com Arduino](https://portal.vidadesilicio.com.br/braco-robotico-com-arduino/) para montar a estrutura física do braço robótico.
   - Certifique-se de que os servos estão firmemente fixados nas posições corretas, de acordo com o manual.

2. **Conexão do Regulador de Tensão LM2596**:
   - Conecte as células de **3,7V** à entrada do LM2596.
   - Ajuste a saída do LM2596 para fornecer **5V**.

3. **Conexões com a ESP32 e os Servo Motores**:
   - **VOUT+ do LM2596** → **pino VIN da ESP32** e **pinos Vcc dos servos**.
   - **GND do LM2596** → **GND da ESP32** e **GND de todos os servos**.
   - **Pinos de controle dos servos** → GPIOs disponíveis na ESP32 (definidos no código).

## ⚠️ Considerações de Alimentação

- O regulador LM2596 deve ser ajustado para fornecer **5V** para a alimentação dos servos e da ESP32.
- Verifique se as células de 3,7V têm corrente suficiente para acionar todos os quatro servos simultaneamente.

---

## 📄 Licença

Este projeto está sob a licença MIT.

---

Esse README proporciona uma visão geral clara do projeto, abrangendo os objetivos, componentes, montagem e código.
