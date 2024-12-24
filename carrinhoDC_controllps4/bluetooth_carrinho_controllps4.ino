#include <Bluepad32.h>

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
//========================== VER VALORES DE CADA BOTÃO DO CONTROLE NO MONITOR SERIAL [SEE CONTROLLER VALUES IN SERIAL MONITOR] ======================== //

void dumpGamepad(ControllerPtr ctl) {
  Serial.printf(
    "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, "
    "misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
    ctl->index(),        // Controller Index 
    ctl->dpad(),         // D-pad                                               [SETAS]
    ctl->buttons(),      // bitmask of pressed buttons                          [QUALQUER BOTÃO EXCETO AS SETAS] (CADA BOTÃO TEM UM VALOR HEXADECIMAL 0x0000)
    ctl->axisX(),        // (-511 - 512) left X Axis                            [JOYSTICK DA ESQUERDA CIMA(-508) E BAIXO(512)]
    ctl->axisY(),        // (-511 - 512) left Y axis                            [JOYSTICK DA ESQUERDA DIREITA(512) E ESQUERDA(-508)]
    ctl->axisRX(),       // (-511 - 512) right X axis                           [JOYSTICK DA DIREITA CIMA(-508) E BAIXO(512)]
    ctl->axisRY(),       // (-511 - 512) right Y axis                           [JOYSTICK DA DIREITA CIMA(-508) E BAIXO(512)]
    ctl->brake(),        // (0 - 1023): brake button                            [L1 + L2 JUNTOS]
    ctl->throttle(),     // (0 - 1023): throttle (AKA gas) button               [R1 + R2]
    ctl->miscButtons(),  // bitmask of pressed "misc" buttons                   [BOTÕES: SHARE, PS E OPTIONS]
    ctl->gyroX(),        // Gyro X                                              [EIXO X GIROSCÓPIO]
    ctl->gyroY(),        // Gyro Y                                              [EIXO Y GIROSCÓPIO] 
    ctl->gyroZ(),        // Gyro Z                                              [EIXO Z GIROSCÓPIO]
    ctl->accelX(),       // Accelerometer X                                     [EIXO X ACELERÔMETRO]
    ctl->accelY(),       // Accelerometer Y                                     [EIXO Y ACELERÔMETRO]
    ctl->accelZ()        // Accelerometer Z                                     [EIXO Z ACELERÔMETRO]
  );
}

///////////////////////////////////////////////////////////// GAME CONTROLLER ACTIONS SECTION ////////////////////////////////////////////////////////////////////

void processGamepad(ControllerPtr ctl) {
  // Existem diferentes maneiras de consultar se um botão está pressionado.
// Uma das maneiras é consultar cada botão individualmente:
//  a(), b(), x(), y(), l1(), etc...

  //== PS4 X button = 0x0001 ==//

  //-------------X----------------------
  if (ctl->buttons() == 0x0001) {
    // code for when X button is pushed
  }
  if (ctl->buttons() != 0x0001) {
    // code for when X button is released
  }

  //-------------QUADRADO------------------
  //== PS4 Square button = 0x0004 ==//
  if (ctl->buttons() == 0x0004) {
    // code for when square button is pushed
  }
  if (ctl->buttons() != 0x0004) {
    // code for when square button is released
  }

//-------------TRIÂNGULO-------------------
  //== PS4 Triangle button = 0x0008 ==//
  if (ctl->buttons() == 0x0008) {
    // code for when triangle button is pushed
  }
  if (ctl->buttons() != 0x0008) {
    // code for when triangle button is released
  }

  //-----------CIRCULO--------------
  //== PS4 Circle button = 0x0002 ==//
  if (ctl->buttons() == 0x0002) {
    // code for when circle button is pushed
  }
  if (ctl->buttons() != 0x0002) {
    // code for when circle button is released
  }

//================================================= SETAS =============================================================
//== PS4 Dpad UP button = 0x01 ==//

//**************CIMA*************************
  if (ctl->buttons() == 0x01) {
    // code for when dpad up button is pushed
  }

  if (ctl->buttons() != 0x01) {
    // code for when dpad up button is released
  }

//*************BAIXO*************************
//==PS4 Dpad DOWN button = 0x02==//
  if (ctl->buttons() == 0x02) {
    // code for when dpad down button is pushed

  }
  if (ctl->buttons() != 0x02) {
    // code for when dpad down button is released
  }


//== PS4 Dpad LEFT button = 0x08 ==//
//********************ESQUERDA********************
  if (ctl->buttons() == 0x08) {
    // code for when dpad left button is pushed
  }
  if (ctl->buttons() != 0x08) {
    // code for when dpad left button is released
  }

//== PS4 Dpad RIGHT button = 0x04 ==//
//*******************DIREITA***************************
  if (ctl->buttons() == 0x04) {
    // code for when dpad right button is pushed
  }
  if (ctl->buttons() != 0x04) {
    // code for when dpad right button is released
  }

//==================ACIONAR R1 e R2=============================

//== PS4 R1 trigger button = 0x0020 ==//
  if (ctl->buttons() == 0x0020) {
    digitalWrite(27, HIGH);
    digitalWrite(25, HIGH);
    // code for when R1 button is pushed
  }
  if (ctl->buttons() != 0x0020) {
    // code for when R1 button is released
    digitalWrite(27, LOW);
    digitalWrite(25, LOW);
  }

//== PS4 R2 trigger button = 0x0080 ==//
  if (ctl->buttons() == 0x0080) {
    digitalWrite(2, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(27, LOW);
    // code for when R2 button is pushed
  }
  if (ctl->buttons() != 0x0080) {
    digitalWrite(2, LOW);
    // code for when R2 button is released
  }

//=========ACIONAR L1 E L2 ==================

  //== PS4 L1 trigger button = 0x0010 ==//
  if (ctl->buttons() == 0x0010) {
     // Girar o motor para frente
      digitalWrite(26, HIGH);
      digitalWrite(33, HIGH);

    // code for when L1 button is pushed
  }
  if (ctl->buttons() != 0x0010) {
    // code for when L1 button is released
      digitalWrite(26, LOW);
      digitalWrite(33, LOW);
  }

  //== PS4 L2 trigger button = 0x0040 ==//
  if (ctl->buttons() == 0x0040) {
    digitalWrite(27, HIGH);
    digitalWrite(25, LOW);

    // code for when L2 button is pushed
  }
  if (ctl->buttons() != 0x0040) {
    digitalWrite(12, LOW);
    // code for when L2 button is released
  }

//================================================ JOYSTICK ESQUERDO======================================

//== LEFT JOYSTICK - X AXIS ==//

// +++++++++++++++++++JOYSTICK DIREITA CIMA/BAIXO ++++++++++++++++
  if (ctl->axisX()) {
    // code for when right joystick moves along x-axis
  }


//== LEFT JOYSTICK - Y AXIS ==//

// +++++++++++++++++++JOYSTICK DIREITA DIREITA/ESQUERDA++++++++++++++++
  if (ctl->axisY() ) {
    // code for when right joystick moves along y-axis
  }



//__________________________________________SE JOYSTICK ESTIVER MOVIDO INDEPEMDENTE DA INTENSIDADE______________________________
//== LEFT JOYSTICK - UP ==//
// ______________PARA CIMA___________
  if (ctl->axisY() <= -25) {
    // code for when left joystick is pushed up
  }


//______________PARA BAIXO___________
//== LEFT JOYSTICK - DOWN ==//
  if (ctl->axisY() >= 25) {
  }

//______________PARA ESQUERDA___________
//== LEFT JOYSTICK - LEFT ==//
  if (ctl->axisX() <= -25) {
    // code for when left joystick is pushed left -->> // quando o joystick esquerdo é empurrado para a esquerda
  }


//______________PARA DIREITA___________
//== LEFT JOYSTICK - RIGHT ==//
  if (ctl->axisX() >= 25) {
    // code for when left joystick is pushed right -->> // quando o joystick esquerdo é empurrado para a direita
  }


//________________________JOYSTICK PARADO____________________________
//== LEFT JOYSTICK DEADZONE ==//
  if (ctl->axisY() > -25 && ctl->axisY() < 25 && ctl->axisX() > -25 && ctl->axisX() < 25) {
    // code for when left joystick is at idle ->> joystick desativado
  }

//+++++++++++++++++++++++++++++++++++++++++++++++JOYSTICK DA DIREITA++++++++++++++++++++++++++++++++++++++++++++++++

//== RIGHT JOYSTICK - X AXIS ==//
//---------------------PARA CIMA/BAIXO-----------------------
  if (ctl->axisRX()) {
    // code for when right joystick moves along x-axis
  }

//== RIGHT JOYSTICK - Y AXIS ==//
//---------------------PARA DIREITA/ESQUERDA---------------------
  if (ctl->axisRY() ) {
    // code for when right joystick moves along y-axis
  }
  dumpGamepad(ctl);
}


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

//========================================================CONFIGURAÇÕES GERAIS=========================================================

void setup() {
  Serial.begin(115200);  // Inicializa a comunicação serial

//LED'S:
  pinMode(2, OUTPUT); // LED_BUILTIN
  pinMode(12, OUTPUT); //LED VERMELHO

//MOTORES: 
  pinMode(26, OUTPUT); //motor A1
  pinMode(27, OUTPUT); //motor A2

  pinMode(25, OUTPUT); //motor B1
  pinMode(33, OUTPUT); //motor B2

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
void loop(){
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