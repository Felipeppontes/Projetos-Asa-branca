# Projetos-Asa-branca
Repositório destinado para os trabalhos realizados por mim como membro da equipe de eletrônica e sistemas de telecomunicações no projeto de drones e satélites da UFPE.

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
-------------------------------------------------------------------------------------------------------------------------------------

# Carrinho controlado por controle PS5/PS4 e ESP32

## 🎯 Objetivo Geral do Projeto

O objetivo deste projeto é construir um **robô** controlado por **2 motores DC**, utilizando uma **ESP32** como unidade de controle. O sistema será alimentado por 2 células de **3,7V** conectadas a um regulador de tensão ajustável **LM2596**, que garantirá uma tensão estável para os servos e para a ESP32.

## 📐 Componentes Utilizados

- 1x ESP32
- 2x motores DC (como SG90 ou MG995)
- 1x Regulador de tensão LM2596
- 2x Células de 3,7V (Li-ion ou LiPo)
- 
- Fios de conexão e protoboard

## ⚙️ Montagem do Braço Robótico

A parte mecânica do projeto é inspirado no projeto open-source [Buzz Line](https://www.instructables.com/Buzz-Line/), um carrinho robótico controlado remotamente e altamente customizável. Este projeto busca criar uma solução prática e acessível para entusiastas de robótica e sistemas embarcados, utilizando componentes simples e eficientes.
****
## Estrutura do Carrinho

1. **Alimentação**:
   O carrinho é alimentado por **duas células de lítio recarregáveis de 3,7 V**, conhecidas por sua alta densidade de energia e capacidade de recarga. Essas baterias fornecem energia suficiente para o funcionamento de todos os componentes do sistema.


2. **Ponte H L298N**:
   A **ponte H L298N** é um controlador de motores DC amplamente utilizado em projetos de robótica. Ele permite controlar a direção e a velocidade de até dois motores simultaneamente. Este módulo é ideal para projetos como este, pois suporta correntes de até 2A por canal e opera com tensões de até 46V. Sua robustez e facilidade de uso o tornam uma escolha popular entre makers e estudantes.

3. **Motores DC**:
   O carrinho utiliza **motores DC com caixa de redução e eixo duplo**. Esses motores, disponíveis na [RoboCore](https://www.robocore.net/motor-motoredutor/motor-dc-3-6v-com-caixa-de-reducao-e-eixo-duplo?gad_source=1&gclid=Cj0KCQiA1Km7BhC9ARIsAFZfEIvH_HWOC8NjmbgaPcVXBVp2EDmE5qzcz29Rg7HFtozEn8zLGoV0QNIaAgJNEALw_wcB), oferecem torque elevado e maior controle de tração, sendo ideais para aplicações em veículos robóticos.

4. **Controlador ESP32**:
   O **ESP32**, disponível na [RoboCore](https://www.robocore.net/wifi/esp32-wifi-bluetooth?gad_source=1&gclid=Cj0KCQiA1Km7BhC9ARIsAFZfEItKIvW5x2VWmoa3_Ukk3fiGiO0IsD2RH8ewUkYliFsU9Pffk5pXdZQaAj9TEALw_wcB), é o cérebro do projeto. Este microcontrolador é conhecido por sua versatilidade, oferecendo conectividade Wi-Fi e Bluetooth, além de uma excelente capacidade de processamento. No projeto, ele gerencia os comandos enviados pelo controle Bluetooth e controla os motores e demais componentes do carrinho.

6. **Controle Bluetooth PS4**:
   O carrinho é controlado por um **controle Bluetooth compatível com PS4**, disponível no [Mercado Livre](https://www.mercadolivre.com.br/controle-compativel-ps4-bluetooth-pc-gamer-tv-smart-preto-dualshock-4/p/MLB36590147#polycard_client=search_best-seller&wid=MLB3936509319&sid=search). Este controle permite que o usuário envie comandos para o ESP32 de forma prática e intuitiva. Modelos compatíveis com PS5 ou outros controles Bluetooth também podem ser utilizados.

8. **Regulador de Tensão LM2596**:
   O **LM2596** é um regulador de tensão do tipo step-down, ajustável, que converte a tensão das baterias para os níveis necessários para os componentes do sistema. Ele é eficiente e fácil de configurar, garantindo uma alimentação estável para o circuito.
   

## ⚠️ Considerações de Alimentação

- O regulador LM2596 deve ser ajustado para fornecer de **4.5V** a **9V** para a alimentação da ESP32.
- O regulador da Ponte H irá receber a limentação das pilhas de aproximadamente **7.2V** e abaixar para **5V** para alimentar os motores.

# Telemetria com LoRa

## 🎯 Objetivo Geral do Projeto

Este projeto tem como objetivo realizar telemetria entre a estação base e o foguete utilizado na missão Humaitá, permitindo o recebimento de dados em tempo real do foguete e o envio de comandos da estação base para o foguete a uma distância de até 3 km.

## 📡 Componentes Utilizados

- 2x Módulos LoRa da EBYTE modelo E220-900T30
- ESP32 para processamento dos dados no foguete
- Raspberry Pi na estação base para recepção e processamento dos dados
- Antena SMA Male LoRa 5dBi (para o foguete)
- Antena Yagi-Uda (projetada para a frequência utilizada na estação base)

## 🔧 Configuração do Módulo E220-900T30
A configuração do módulo LoRa E220-900T30 será realizada no modo transmissão fixa. Para entender melhor como configurar e programar o módulo, consulte os seguintes materiais:

- Configuração e Programação - Vídeo 1 (https://www.youtube.com/watch?v=h6PLXrxV66Q)
- Configuração e Programação - Vídeo 2 (https://www.youtube.com/watch?v=Pu0-391iKC8)
- Guia MicroPeta (https://www.micropeta.com/video1)

## 📜 Biblioteca Utilizada
A principal biblioteca utilizada no projeto é a EByte LoRa E220 Series Library, disponível no GitHub:
https://github.com/xreef/EByte_LoRa_E220_Series_Library

Essa biblioteca fornece uma interface simplificada para comunicação com os módulos EBYTE LoRa, permitindo fácil configuração e transmissão de dados.

## 📡 Projeto de Antenas
Para garantir uma comunicação eficiente entre a estação base e o foguete, utilizaremos:

- Antena para o foguete: SMA Male LoRa Antena 5dBi
- Antena para a estação base: Yagi-Uda projetada para a frequência utilizada
- Materiais para o projeto das antenas:
- Projeto Antena Yagi-Uda - Vídeo 1 (https://youtu.be/444sTTpWWzw?si=g0ieaR5HW8kkrCAz)
- Projeto Antena Yagi-Uda - Vídeo 2 (https://youtu.be/R1HdDT5lDlM?si=piKj0uEXso6Vrnh_)
- Simulador de Antenas (https://youtu.be/d5oTMlDGldU?si=2umriPPiTrR88a_e)

## 📡 Estrutura do Sistema

### Foguete:

- ESP32 coleta e transmite os dados via LoRa.
- Alimentação independente.
- Comunicação contínua com a estação base.

### Estação Base:

- Raspberry Pi recebe os dados e processa.
- Conexão via LoRa com o foguete.
- Interface gráfica para exibição dos dados.

## 🚀 Conclusão
Este projeto busca fornecer uma solução robusta para telemetria de foguetes, garantindo uma comunicação eficiente e confiável entre o foguete e a estação base. A utilização do LoRa permite longas distâncias de comunicação com baixo consumo de energia, essencial para aplicações aeroespaciais.





