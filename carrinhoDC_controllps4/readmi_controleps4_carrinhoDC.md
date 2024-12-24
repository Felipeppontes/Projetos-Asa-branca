Esse código é referente ao projeto do asa Branca, usado na confraternização dia 14/12 para controlar o carrinho com 2 motores DC responsáveis pelo movimento do robô, com um controle de PS5/PS4 conectado ao bluetooth da esp32. O código está todo comentado e reduzido ao máximo para melhor compreensão. 

A ideia é implementar mais recursos a ideia, com:
- FreeRTOS --> para realizar controle de atitudes de forma paralela;
- Construir uma placa de circuito impresso para toda parte elétrica e eletrônica do robô;
- Controle de potencia dos movimentos --> PWM;

# Controle de Carrinho DC com ESP32 e Controle PS4/PS5

Este projeto demonstra como controlar um carrinho com motores DC utilizando um ESP32 e um controle de PS4 ou PS5 via Bluetooth.

## Materiais Necessários

- ESP32
- Dois motores DC
- Módulo driver de motor (por exemplo, L298N)
- Controle PS4 ou PS5
- Biblioteca Bluepad32

## Instalação da Biblioteca Bluepad32

1. Abra o Arduino IDE.
2. Vá em **Sketch** > **Incluir Biblioteca** > **Gerenciar Bibliotecas**.
3. Procure por "Bluepad32" e instale a biblioteca.

## Conexões

1. Conecte os motores DC ao módulo driver de motor.
2. Conecte o módulo driver ao ESP32 conforme a pinagem definida no código.
3. Assegure-se de que o ESP32 e o módulo driver estejam alimentados corretamente.

## Código
O código enviado é bem detalhado e contém várias partes importantes para diferentes funcionalidades, como o controle de motores e LEDs, além da integração com um controle PS4 via Bluetooth. Aqui estão as partes principais destacadas e o que cada uma faz:

### **1. Inicialização e Configuração**
- **`setup()`**: 
  - Configura a comunicação serial.
  - Define os pinos de saída para LEDs e motores.
  - Inicializa o Bluetooth usando a biblioteca `Bluepad32`.
  - Configura callbacks para eventos de conexão e desconexão de controles.
  - Chama funções auxiliares como `forgetBluetoothKeys()` para evitar problemas de pareamento.

### **2. Callbacks para Conexão e Desconexão**
- **`onConnectedController()`**:
  - Detecta quando um controle é conectado.
  - Exibe informações sobre o controle (modelo, VID, PID).
  - Aloca o controle em um slot disponível.

- **`onDisconnectedController()`**:
  - Detecta quando um controle é desconectado.
  - Libera o slot associado ao controle desconectado.

### **3. Leitura e Processamento dos Dados do Controle**
- **`dumpGamepad(ControllerPtr ctl)`**:
  - Exibe os valores dos botões, eixos dos joysticks, acelerômetro e giroscópio no monitor serial.
  - Ajuda no debug e visualização do estado atual do controle.

- **`processGamepad(ControllerPtr ctl)`**:
  - Processa os comandos do controle, como botões pressionados e movimentos dos joysticks.
  - Exemplos:
    - Detecta botões específicos (e.g., `X`, `Círculo`, `R1`, etc.).
    - Verifica o movimento dos joysticks (e.g., eixo X e Y).
    - Executa ações específicas como ativar motores ou LEDs.

### **4. Controle dos Motores**
- **Pinos Configurados**:
  - `26` e `27`: Motor A.
  - `25` e `33`: Motor B.

- **Lógica nos Botões**:
  - Exemplo: `R1` ativa os motores A e B para frente.
  - `L2` e `R2` alteram os estados dos motores.

### **5. Loop Principal**
- **`loop()`**:
  - Chama `processControllers()` para verificar o estado de todos os controles conectados.
  - Responsável por manter o sistema em funcionamento contínuo.

---

Se precisar de ajuda para ajustar ou detalhar partes específicas do código, é só pedir!
## Referências

- [Bluepad32 GitHub Repository](https://github.com/ricardoquesada/bluepad32)
- [Bluepad32 Documentation](https://bluepad32.readthedocs.io/)

Para uma demonstração visual de como conectar o controle PS4 ao ESP32 via Bluetooth, você pode assistir ao seguinte vídeo:

 
