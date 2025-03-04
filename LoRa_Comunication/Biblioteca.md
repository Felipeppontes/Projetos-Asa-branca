# E220Lib - Biblioteca para Comunicação LoRa com E220-900T30D

## 📌 Introdução
**E220Lib** é uma biblioteca para Arduino e ESP32 projetada para facilitar a comunicação LoRa utilizando os módulos **E220-900T30D** da Ebyte, utilizando a biblioteca correta: [EByte LoRa E220 Series Library](https://github.com/xreef/EByte_LoRa_E220_Series_Library).

Com essa biblioteca, é possível configurar e enviar dados via LoRa de forma eficiente, utilizando comandos simples para gerenciar os modos de operação, transmissão e recepção de pacotes.

---

## 🚀 Recursos Principais

✅ Suporte para **múltiplos modos de operação** (Normal, Wake-up, Configuração, Sono)  
✅ **Fácil configuração** dos parâmetros de comunicação (frequência, potência, taxa de transmissão)  
✅ **Envio e recepção de pacotes LoRa** com tratamento de erros  
✅ **Gerenciamento automático de M0, M1 e AUX** para melhor desempenho  
✅ **Compatível com Arduino e ESP32**  

---

## 🔧 Instalação

1. Baixe e instale a biblioteca diretamente do [GitHub](https://github.com/xreef/EByte_LoRa_E220_Series_Library).
2. Copie a pasta `EByte_LoRa_E220_Series_Library` para o diretório `libraries` do Arduino (`Documents/Arduino/libraries`).
3. Reinicie o Arduino IDE e inclua a biblioteca no seu código:

```cpp
#include <EByte_LoRa_E220.h>
```

---

## 🗀 Pinos e Conexão

| **Pino Módulo E220** | **Pino Arduino/ESP32** | **Descrição** |
|----------------------|----------------------|--------------|
| TX                 | RX                   | Comunicação Serial |
| RX                 | TX                   | Comunicação Serial |
| M0                 | D5                   | Controle de Modo |
| M1                 | D4                   | Controle de Modo |
| AUX                | D2                   | Indicação de Estado |
| VCC (5V)           | 5V (Arduino/Externo) | Alimentação |
| GND                | GND                  | Terra |

> ⚠ **Importante:** O módulo E220-900T30D opera em **3.3V**. Se estiver usando um Arduino de 5V, utilize um **conversor de nível lógico** nos pinos TX e RX.

---

## 🔄 Modos de Operação
A biblioteca gerencia automaticamente os modos do módulo através dos pinos **M0 e M1**:

| **Modo**         | **M0** | **M1** | **Descrição** |
|-----------------|------|------|--------------|
| Normal         | 0    | 0    | Modo padrão para comunicação |
| Wake-up       | 1    | 0    | Acorda o receptor para comunicação |
| Configuração  | 0    | 1    | Ajusta parâmetros do módulo |
| Modo Sono     | 1    | 1    | Baixo consumo de energia |

---

## 📡 Exemplo de Código (Envio e Recebimento de Dados)

### **1️⃣ Inicialização do Módulo**

```cpp
#include <EByte_LoRa_E220.h>

EByte_LoRa_E220 e220(&Serial2, 5, 4, 2); // UART2, M0, M1, AUX

void setup() {
    Serial.begin(9600);
    e220.begin();
    Serial.println("Módulo E220 iniciado com sucesso!");
}
```

### **2️⃣ Envio de Dados**

```cpp
void loop() {
    String mensagem = "Ola, LoRa!";
    e220.sendMessage(mensagem);
    Serial.println("Mensagem enviada: " + mensagem);
    delay(2000);
}
```

### **3️⃣ Recebimento de Dados**

```cpp
void loop() {
    if (e220.available()) {
        String mensagemRecebida = e220.receiveMessage();
        Serial.println("Mensagem recebida: " + mensagemRecebida);
    }
}
```

---

## ⚙️ Configuração Avançada
Ajuste parâmetros como **potência de transmissão**, **frequência**, **endereço do módulo**:

```cpp
e220.setAddress(0x01);       // Define o endereço do módulo
e220.setChannel(0x10);       // Define o canal de comunicação
e220.setPower(30);           // Define a potência de transmissão (máx: 30dBm)
```

---

## 🔎 Debug e Testes
Para verificar se o módulo está respondendo corretamente, utilize:

```cpp
e220.printParameters(); // Exibe os parâmetros atuais no Serial Monitor
```

---

## 📚 Documentação Oficial
- [Repositório no GitHub](https://github.com/xreef/EByte_LoRa_E220_Series_Library)
- [Manual do Módulo E220-900T30D](https://manuals.plus/pt/ebyte/e220-900t30d-lora-wireless-module-manual)
- [Datasheet do Módulo](https://manuals.plus/m/12f09f3a998def18a583f07ae19dc04635512c1a83f96d39c0d124afbfc82ca1_optim.pdf)

---

## 🤝 Contribuições
Caso encontre bugs ou tenha sugestões de melhorias, abra uma *issue* ou envie um *pull request* no repositório do GitHub!

---

## 💎 Contato
Se tiver dúvidas, entre em contato através do repositório do GitHub ou fóruns da comunidade Arduino e ESP32.

