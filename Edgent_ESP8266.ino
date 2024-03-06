//#define BLYNK_TEMPLATE_ID "TMPL3LjWDPCQi"
//#define BLYNK_TEMPLATE_NAME "Voltage Sensor"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG


#include "BlynkEdgent.h"
const int voltagePin = A0; // Analog pin to read voltage

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  int sensorValue = analogRead(voltagePin); // Read analog voltage
 // Serial.print(sensorValue);
  float voltage = sensorValue * (5 / 1023.0); // Convert analog value to voltage (assuming 5V Arduino)
  Serial.print("Measured Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(1000); // Delay for 1 second
  Blynk.virtualWrite(V0, voltage);
}

