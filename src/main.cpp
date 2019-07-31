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
  
  LED an GPIO4.

*/
#include <Arduino.h>

int LED_SIG = 4;

int ADC1_PINS[] = {36,34,33,32};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\nESP32 NodeMCU-32\n");
  // initialisiere ADC Interface
  analogSetWidth(10);                   // mögliche Werte: 10-12 
  analogSetAttenuation(ADC_11db);       // bei Poti an 3.3V Spannung 
  // LED
  pinMode(LED_SIG,OUTPUT);
  digitalWrite(LED_SIG, LOW);
}

long counter = 0;

void loop() {
  // Photoresistor an ADC1_CH0 (36)
  int value = analogRead(36);           // lese analogen Wert an ADC0 (GPIO36, VP)
  counter += 1;
  Serial.print(counter);
  Serial.print(" ");
  Serial.print(value);
  // LED-Steuerung 
  delay( 2 * value + 100);
  digitalWrite(LED_SIG,HIGH);
  delay(50);
  digitalWrite(LED_SIG,LOW);
  // Alle ADC1 analoger Input lesen und anzeigen
  Serial.print(" -");
  int c = sizeof(ADC1_PINS)/sizeof(int);
  for (int i = 0; i < c; i++) {
    Serial.print(" ");
    Serial.print(ADC1_PINS[i]);
    Serial.print(": ");
    Serial.print(analogRead(ADC1_PINS[i]));
  }
  // Newline
  Serial.println();
}
