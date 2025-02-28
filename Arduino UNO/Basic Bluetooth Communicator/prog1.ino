#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
    Serial.begin(9600);   // Serial Monitor
    BTSerial.begin(9600); // HC-05 Bluetooth module
    Serial.println("Bluetooth Module Ready");
}

void loop() {
    // Receive data from Bluetooth
    if (BTSerial.available()) {
        String received = "";
        while (BTSerial.available()) {
            received += (char)BTSerial.read();
            delay(10); // Small delay for stability
        }
        Serial.print("From Bluetooth: ");
        Serial.println(received);

        // Send back acknowledgment to Bluetooth
        BTSerial.print("Arduino Received: ");
        BTSerial.println(received);
    }

    // Receive data from Serial Monitor and send it to Bluetooth
    if (Serial.available()) {
        String sendData = "";
        while (Serial.available()) {
            sendData += (char)Serial.read();
            delay(10); // Small delay for stability
        }
        BTSerial.println(sendData);
    }
}
