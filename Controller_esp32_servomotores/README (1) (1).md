Aqui está um modelo de README detalhado para o projeto de controle de um braço robótico via Bluetooth com um controle de PS4/PS5 e ESP32. Esse guia inclui todas as etapas para conectar o controle, configurar a eletrônica e controlar os servos:

---

# Controle de Braço Robótico com ESP32 e Controle PS4/PS5 via Bluetooth

Este projeto demonstra como conectar um controle de PS4 ou PS5 a um ESP32 via Bluetooth para manipular servos de um braço robótico. Com o uso do joystick do controle, é possível controlar diretamente os ângulos dos servos, permitindo movimentos precisos para o braço robótico. Este projeto é baseado em um tutorial e outros projetos de referência, incluindo [este vídeo tutorial no YouTube](https://www.youtube.com/watch?v=EEViXFoSzww&t=50s) e [esse projeto similar no GitHub](https://github.com/Felipeppontes/Projetos-Asa-branca/blob/main/Controller_esp32_servomotores/README%20(1)%20(1).md).

---

## Sumário
- [Bibliotecas e Ferramentas Necessárias](#bibliotecas-e-ferramentas-necessárias)
- [Configuração do Hardware](#configuração-do-hardware)
- [Passo a Passo de Configuração](#passo-a-passo-de-configuração)
- [Explicação do Código](#explicação-do-código)
- [Conexões de Eletrônica](#conexões-de-eletrônica)

---

### Bibliotecas e Ferramentas Necessárias

1. **ESP32Servo**  
   Biblioteca usada para controlar os servos no ESP32. Ela facilita o uso de comandos básicos para controle de ângulo, simplificando a configuração dos pinos para os servos.

   - **Instalação**: Esta biblioteca pode ser instalada diretamente pela IDE do Arduino em *Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...*.
   - **Características**: Permite controlar servos com precisão no ESP32, com comandos simples para setar ângulos entre 0 e 180 graus.
   - **Exemplo de Uso**:
     ```cpp
     #include <ESP32Servo.h>

     Servo servo1;
     servo1.attach(servoPin);  // Define o pino do servo
     servo1.write(90);         // Define o ângulo inicial do servo
     ```

2. **Bluepad32**  
   A biblioteca `Bluepad32` é responsável pela conexão Bluetooth entre o controle PS4/PS5 e o ESP32, facilitando o acesso aos dados dos eixos e botões do controle.

   - **Instalação**: Acesse o *Gerenciador de Bibliotecas* e pesquise por "Bluepad32" para instalar.
   - **Características**: Suporte a controles PS4, PS5 e outros, fornecendo acesso a dados dos eixos dos joysticks, botões e até sensores (acelerômetro e giroscópio).
   - **Exemplo de Conexão**:
     ```cpp
     #include <Bluepad32.h>

     void setup() {
         BP32.setup(&onConnectedController, &onDisconnectedController);
     }

     void loop() {
         bool dataUpdated = BP32.update();
         if (dataUpdated) {
             processControllers();
         }
     }
     ```

3. **Bluetooth Devices Info (App)**  
   Para parear com um controle específico, você precisa do endereço MAC do controle. Para obter o endereço MAC, use o aplicativo `Bluetooth Devices Info`, disponível na Play Store ou App Store.

   - **Uso**: Abra o app, conecte o controle ao dispositivo e copie o endereço MAC exibido.

---

### Configuração do Hardware

#### Componentes Necessários:
- **ESP32**
- **Servos (4)**: Conectados ao braço robótico
- **Fonte de alimentação externa** (baterias 3.7V com regulador LM2596)
- **Controle PS4/PS5**

---

### Passo a Passo de Configuração

1. **Conectar o Controle ao ESP32**  
   - Ligue o controle de PS4 ou PS5 em modo de emparelhamento, pressionando e segurando os botões `PS` e `Share` ao mesmo tempo até que a luz comece a piscar.
   - No ESP32, utilize a biblioteca `Bluepad32` para escanear dispositivos e conectar-se ao controle.
   - Verifique a saída serial para confirmar a conexão e visualizar os dados do controle.

2. **Instalar Bibliotecas no Arduino IDE**
   - Abra o Arduino IDE, vá em *Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...*
   - Instale `ESP32Servo` para controle dos servos.
   - Instale `Bluepad32` para conexão Bluetooth com o controle.

3. **Configuração do Código**  
   O código se conecta ao controle, lê o estado do joystick e usa esses valores para definir o ângulo dos servos, controlando o movimento do braço.

4. **Identificar Endereço MAC do Controle (Opcional)**  
   Caso utilize outra biblioteca para o controle, é necessário definir o endereço MAC. Utilize o app `Bluetooth Devices Info` para descobrir o endereço MAC do controle e inserir no código.

---

### Explicação do Código

```cpp
#include <ESP32Servo.h>
#include <Bluepad32.h>

Servo servo1, servo2, servo3, servo4;
ControllerPtr myControllers[BP32_MAX_GAMEPADS];

void setup() {
    Serial.begin(115200);
    BP32.setup(&onConnectedController, &onDisconnectedController);

    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
    servo3.attach(servoPin3);
    servo4.attach(servoPin4);
}

void loop() {
    bool dataUpdated = BP32.update();
    if (dataUpdated) processControllers();
}

void processControllers() {
    for (auto myController : myControllers) {
        if (myController && myController->isConnected()) {
            int angleX = map(myController->axisRX(), -511, 512, 0, 180);
            servo1.write(angleX);
        }
    }
}

void onConnectedController(ControllerPtr ctl) {
    Serial.println("Controle conectado.");
    myControllers[ctl->index()] = ctl;
}

void onDisconnectedController(ControllerPtr ctl) {
    Serial.println("Controle desconectado.");
    myControllers[ctl->index()] = nullptr;
}
```

### Explicação:
- **`BP32.update()`**: Atualiza o status do controle, verificando se há novas entradas.
- **Mapeamento de Ângulos**: Utiliza `map()` para ajustar o ângulo de controle dos servos com base nos valores do joystick.
- **Funções de Conexão**: Funções de callback para detectar quando o controle conecta/desconecta.

---

### Conexões de Eletrônica

- **Fonte de Alimentação**: Utilize uma fonte de 3.7V com regulador LM2596 para manter uma tensão estável para os servos.
- **Conexão dos Servos**:
   - **GND**: Conecte ao GND do ESP32.
   - **VCC**: Conecte à saída regulada de 5V do LM2596.
   - **Sinal**: Conecte o pino de controle ao pino digital do ESP32 configurado no código (`servoPin1`, `servoPin2`, etc.).

---

### Observações

1. **Atenção com a Corrente**: Servos podem exigir mais corrente que o ESP32 fornece. Portanto, o uso de uma fonte regulada é essencial.
2. **Calibração dos Servos**: Teste os ângulos dos servos e ajuste o mapeamento de acordo com a posição desejada para o braço robótico.
3. **Teste de Resposta do Controle**: Use a função `dumpGamepad()` para verificar o estado do controle no monitor serial, garantindo que todos os eixos e botões funcionem conforme esperado.

### Links Úteis

- [ESP32Servo Library no GitHub](https://github.com/RoboticsBrno/ESP32-Arduino-Servo-Library)
- [Bluepad32 Library no GitHub](https://github.com/ricardoquesada/Bluepad32)
- [Aplicativo Bluetooth Devices Info](https://play.google.com/store/apps/details?id=com.bluetooth.deviceinfo)

---

Esse projeto proporciona controle remoto preciso de um braço robótico, tornando-o adequado para aplicações de manipulação e aprendizado em robótica e automação.
