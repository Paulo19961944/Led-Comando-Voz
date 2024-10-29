// INCLUSÃO DA BIBLIOTECA
#include <BluetoothSerial.h>

BluetoothSerial SerialBT; // Instancia o Objeto BluetoothSerial
const int LED_PIN = 32; // Define o pino do LED
String comando; // Comando do Led

// SETUP INICIAL
void setup() {
  pinMode(LED_PIN, OUTPUT); // Define o pino do LED como Saída
  SerialBT.begin("ESP32_LED"); // Nome do Dispositivo Bluetooth
}

// FUNÇÃO LOOP
void loop() {
  // SE TIVER DADOS DE BLUETOOTH
  if (SerialBT.available()) {
    comando = SerialBT.readStringUntil('\n'); // Leia o Comando até a nova linha
    comando.toLowerCase(); // Converte o comando para minúsculas

    // SE LIGAR
    if (comando == "ligar led") {
      digitalWrite(LED_PIN, HIGH); // Liga o LED
      SerialBT.println("Led Aceso"); // Mensagem de LED Aceso
    }
    // SE DESLIGAR
    else if (comando == "desligar led") {
      digitalWrite(LED_PIN, LOW); // Apaga o LED
      SerialBT.println("Led Apagado"); // Mensagem de LED Apagado
    }
    // SENÃO
    else {
      SerialBT.println("Comando Inválido"); // Comando Inválido
    }
  }
}
