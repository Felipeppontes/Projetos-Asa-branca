#include <ESP32Servo.h>

#include <Bluepad32.h>

static const int servoPin1 = 25;  // Pino de controle do servo 
static const int servoPin2 = 32;  // Pino de controle do servo
static const int servoPin3 = 14;  // Pino de controle do servo
static const int servoPin4 = 27;  // Pino de controle do servo

//static const int potPin1 = 35;    // Pino analógico para o potenciômetro
Servo servo1;                     // Objeto servo
Servo servo2;
Servo servo3;
Servo servo4;


ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedController(ControllerPtr ctl) {
  bool foundEmptySlot = false;
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == nullptr) {
      Serial.printf("CALLBACK: Controller is connected, index=%d\n", i);
      // Additionally, you can get certain gamepad properties like:
      // Model, VID, PID, BTAddr, flags, etc.
      ControllerProperties properties = ctl->getProperties();
      Serial.printf("Controller model: %s, VID=0x%04x, PID=0x%04x\n", ctl->getModelName().c_str(), properties.vendor_id, properties.product_id);
      myControllers[i] = ctl;
      foundEmptySlot = true;
      break;
    }
  }
  if (!foundEmptySlot) {
    Serial.println("CALLBACK: Controller connected, but could not found empty slot");
  }
}

void onDisconnectedController(ControllerPtr ctl) {
  bool foundController = false;

  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == ctl) {
      Serial.printf("CALLBACK: Controller disconnected from index=%d\n", i);
      myControllers[i] = nullptr;
      foundController = true;
      break;
    }
  }

  if (!foundController) {
    Serial.println("CALLBACK: Controller disconnected, but not found in myControllers");
  }
}

// ========= SEE CONTROLLER VALUES IN SERIAL MONITOR ========= //

void dumpGamepad(ControllerPtr ctl) {
  Serial.printf(
    "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, "
    "misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
    ctl->index(),        // Controller Index
    ctl->dpad(),         // D-pad
    ctl->buttons(),      // bitmask of pressed buttons
    ctl->axisX(),        // (-511 - 512) left X Axis
    ctl->axisY(),        // (-511 - 512) left Y axis
    ctl->axisRX(),       // (-511 - 512) right X axis
    ctl->axisRY(),       // (-511 - 512) right Y axis
    ctl->brake(),        // (0 - 1023): brake button
    ctl->throttle(),     // (0 - 1023): throttle (AKA gas) button
    ctl->miscButtons(),  // bitmask of pressed "misc" buttons
    ctl->gyroX(),        // Gyro X
    ctl->gyroY(),        // Gyro Y
    ctl->gyroZ(),        // Gyro Z
    ctl->accelX(),       // Accelerometer X
    ctl->accelY(),       // Accelerometer Y
    ctl->accelZ()        // Accelerometer Z
  );
}


///////////////////////////////////////////////////////////// GAME CONTROLLER ACTIONS SECTION ////////////////////////////////////////////////////////////////////

void processGamepad(ControllerPtr ctl) {
  // Existem diferentes maneiras de consultar se um botão está pressionado.
// Uma das maneiras é consultar cada botão individualmente:
//  a(), b(), x(), y(), l1(), etc...

  //== PS4 X button = 0x0001 ==//
  if (ctl->buttons() == 0x0001) {
    // code for when X button is pushed
  }
  if (ctl->buttons() != 0x0001) {
    // code for when X button is released
  }
  //== PS4 Square button = 0x0004 ==//
  if (ctl->buttons() == 0x0004) {
    // code for when square button is pushed
  }
  if (ctl->buttons() != 0x0004) {
    // code for when square button is released
  }
  //== PS4 Triangle button = 0x0008 ==//
  if (ctl->buttons() == 0x0008) {
    // code for when triangle button is pushed
  }
  if (ctl->buttons() != 0x0008) {
    // code for when triangle button is released
  }
  //== PS4 Circle button = 0x0002 ==//
  if (ctl->buttons() == 0x0002) {
    // code for when circle button is pushed
  }
  if (ctl->buttons() != 0x0002) {
    // code for when circle button is released
  }


//=========================================================================DPAD's=============================================================
//== PS4 Dpad UP button = 0x01 ==//
  /*if (ctl->buttons() == 0x01) {
  // Mapeia o movimento para o servo, movendo-o para cima (aumentando o ângulo)
    int angle = servo1.read();  // Obtém o ângulo atual do servo
    angle = min(angle + 20, 180);  // Incrementa o ângulo, limitando a 180 graus
    servo1.write(angle);
    delay(5);  // Pequeno atraso para suavizar o movimento
    // code for when dpad up button is pushed
  }

  if (ctl->buttons() != 0x01) {
    // code for when dpad up button is released
  }

//==PS4 Dpad DOWN button = 0x02==//
  if (ctl->buttons() == 0x02) {

     // Mapeia o movimento para o servo, movendo-o para baixo (diminuindo o ângulo)
    int angle = servo1.read();  // Obtém o ângulo atual do servo
    angle = max(angle - 20, 0);  // Decrementa o ângulo, limitando a 0 graus
    servo1.write(angle);
    delay(5);  // Pequeno atraso para suavizar o movimento
    // code for when dpad down button is pushed

  }*/
  if (ctl->buttons() != 0x02) {
    // code for when dpad down button is released
  }
//== PS4 Dpad LEFT button = 0x08 ==//
  if (ctl->buttons() == 0x08) {
    // code for when dpad left button is pushed
  }
  if (ctl->buttons() != 0x08) {
    // code for when dpad left button is released
  }
//== PS4 Dpad RIGHT button = 0x04 ==//
  if (ctl->buttons() == 0x04) {
    // code for when dpad right button is pushed
  }
  if (ctl->buttons() != 0x04) {
    // code for when dpad right button is released
  }


//==================ACIONAR LEDS VERDE E VERMELHO COM R1(VERMELHO) E R2 (VERDE)=================================

//== PS4 R1 trigger button = 0x0020 ==//
  if (ctl->buttons() == 0x0020) {
    digitalWrite(26, HIGH);

    // code for when R1 button is pushed
  }
  if (ctl->buttons() != 0x0020) {
    digitalWrite(26, LOW);
    // code for when R1 button is released
  }

//== PS4 R2 trigger button = 0x0080 ==//
  if (ctl->buttons() == 0x0080) {
    digitalWrite(13, HIGH);

    // code for when R2 button is pushed
  }
  if (ctl->buttons() != 0x0080) {
    digitalWrite(13, LOW);

    // code for when R2 button is released
  }



//=====================ACIONAR L1 (LED DA PLACA-D2) E L2 (BUZZER-12)=====================================

//LED_BUILTIN

  //== PS4 L1 trigger button = 0x0010 ==//
  if (ctl->buttons() == 0x0010) {
    digitalWrite(2, HIGH);

    // code for when L1 button is pushed
  }
  if (ctl->buttons() != 0x0010) {
    digitalWrite(2, LOW);

    // code for when L1 button is released
  }

//BUZZER

  //== PS4 L2 trigger button = 0x0040 ==//
  if (ctl->buttons() == 0x0040) {
    digitalWrite(12, HIGH);

    // code for when L2 button is pushed
  }
  if (ctl->buttons() != 0x0040) {
    digitalWrite(12, LOW);

    // code for when L2 button is released
  }


//================================================ JOYSTICK ESQUERDO======================================



//== LEFT JOYSTICK - X AXIS ==//
  if (ctl->axisX()) {
    // code for when right joystick moves along x-axis
    int eixolx = ctl->axisX();  // Use ctl->axisRY() em vez de axisRY()

    // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
    int angle = map(eixolx, -511, 512, 180, 0);

    // Move o servo para o ângulo correspondente
    servo3.write(angle);
    delay(15);
    
  }

  
//== LEFT JOYSTICK - Y AXIS ==//
  if (ctl->axisY() ) {
    // code for when right joystick moves along y-axis
     int eixoly = ctl->axisY();  // Use ctl->axisRY() em vez de axisRY()
     

    // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
    int angle = map(eixoly, -550, 512, 0, 180); //ESTÁ INVERTIDO O MOVIMENTO DO SERVO

    // Move o servo para o ângulo correspondente
    servo4.write(angle);
    delay(15);
  }




/*
//== LEFT JOYSTICK - UP ==//
  if (ctl->axisY() <= -25) {
    int eixoy = ctl->axisRY();  // Use ctl->axisRY() em vez de axisRY()


    // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
    int angle = map(eixoy, -511, 0, 0, 180);


    // Move o servo para o ângulo correspondente
    servo3.write(angle);
    delay(15);

    // code for when left joystick is pushed up
  }



//== LEFT JOYSTICK - DOWN ==//
  if (ctl->axisY() >= 25) {
    int eixoy = ctl->axisRY();  // Use ctl->axisRY() em vez de axisRY()

    int angle = map(eixoy, 0, 512, 0, 180);

      // Move o servo para o ângulo correspondente
      servo3.write(angle);
      delay(15);  // Pequeno atraso para suavizar o movimento
    
  }


*/
//== LEFT JOYSTICK - LEFT ==//
  if (ctl->axisX() <= -25) {
    // code for when left joystick is pushed left -->> // quando o joystick esquerdo é empurrado para a esquerda
  }

//== LEFT JOYSTICK - RIGHT ==//
  if (ctl->axisX() >= 25) {
    // code for when left joystick is pushed right -->> // quando o joystick esquerdo é empurrado para a direita
  }

//== LEFT JOYSTICK DEADZONE ==//
  if (ctl->axisY() > -25 && ctl->axisY() < 25 && ctl->axisX() > -25 && ctl->axisX() < 25) {
    // code for when left joystick is at idle ->> joystick esquerdo desativado
  }







//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++JOYSTICK DA DIREITA++++++++++++++++++++++++++++++++++++++++++++++++==

//== RIGHT JOYSTICK - X AXIS ==//
  if (ctl->axisRX()) {
    // code for when right joystick moves along x-axis
    int eixox = ctl->axisRX();  // Use ctl->axisRY() em vez de axisRY()

    // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
    int angle = map(eixox, -511, 512, 0, 180);

    // Move o servo para o ângulo correspondente
    servo2.write(angle);
    delay(15);
    
  }


//== RIGHT JOYSTICK - Y AXIS ==//
  if (ctl->axisRY() ) {
    // code for when right joystick moves along y-axis
     int eixoy = ctl->axisRY();  // Use ctl->axisRY() em vez de axisRY()

    // Mapeia o valor do potenciômetro para o ângulo do servo (0 a 180)
    int angle = map(eixoy, -511, 512, 180, 0); //ESTÁ INVERTIDO O MOVIMENTO DO SERVO

    // Move o servo para o ângulo correspondente
    servo1.write(angle);
    delay(15);
  }
  dumpGamepad(ctl);
}







//-------------------------------------CONFIGURAÇÕES GERAIS-------------------------------------------------------


void processControllers() {
  for (auto myController : myControllers) {
    if (myController && myController->isConnected() && myController->hasData()) {
      if (myController->isGamepad()) {
        processGamepad(myController);
      } else {
        Serial.println("Unsupported controller");
      }
    }
  }
}
// Arduino setup function. Runs in CPU 1
void setup() {

  Serial.begin(115200);  // Inicializa a comunicação serial

//SERVOS: 
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);




//PINOS:
  pinMode(2, OUTPUT); // LED_BUILTIN
  pinMode(13, OUTPUT); //LED VERMELHO
  pinMode(26, OUTPUT); //LED VERDE
  pinMode(12, OUTPUT);


  Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
  const uint8_t* addr = BP32.localBdAddress();
  Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

  // Setup the Bluepad32 callbacks
  BP32.setup(&onConnectedController, &onDisconnectedController);

  // "forgetBluetoothKeys()" should be called when the user performs
  // a "device factory reset", or similar.
  // Calling "forgetBluetoothKeys" in setup() just as an example.
  // Forgetting Bluetooth keys prevents "paired" gamepads to reconnect.
  // But it might also fix some connection / re-connection issues.
  BP32.forgetBluetoothKeys();

  // Enables mouse / touchpad support for gamepads that support them.
  // When enabled, controllers like DualSense and DualShock4 generate two connected devices:
  // - First one: the gamepad
  // - Second one, which is a "virtual device", is a mouse.
  // By default, it is disabled.
  BP32.enableVirtualDevice(false);
}
// Arduino loop function. Runs in CPU 1.
void loop() {
  // This call fetches all the controllers' data.
  // Call this function in your main loop.
  bool dataUpdated = BP32.update();
  if (dataUpdated)
    processControllers();

  // The main loop must have some kind of "yield to lower priority task" event.
  // Otherwise, the watchdog will get triggered.
  // If your main loop doesn't have one, just add a simple `vTaskDelay(1)`.
  // Detailed info here:
  // https://stackoverflow.com/questions/66278271/task-watchdog-got-triggered-the-tasks-did-not-reset-the-watchdog-in-time
  // vTaskDelay(1);
  delay(150);
}