/*
  URL: https://github.com/xd23fe39/ESP32-AnalogDigitalTest

  Erfolgreich getestet auf:
  - Espressif ESP32 WLAN Dev Kit Board Development Bluetooth Wifi v1 WROOM32 NodeMCU

  PIN Layout:

  ESP32        | Poti
  -------------|----------
  3V3          | VCC
  GND          | GND
  VP (GPIO36)  | SIG

*/
#include "Arduino.h"

unsigned long counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\nESP32 NodeMCU-32\n");
  // initialisiere ADC Interface
  analogSetWidth(10);                   // mögliche Werte: 10-12 
  analogSetAttenuation(ADC_11db);       // bei Poti an 3.3V Spannung 
}

void loop() {
  int analog_in;
  analog_in = analogRead(36);           // lese analogen Wert an ADC0 (GPIO36, VP)
  Serial.print(++counter);
  Serial.print(" ");
  Serial.print(analog_in);
  Serial.println();
  delay(1000);
}
