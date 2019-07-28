#include <Arduino.h>

long treffer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\nESP32 NodeMCU-32\n");
  // initialisiere ADC Interface
  analogSetWidth(12);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  int analog_in;
  analog_in = analogRead(36);
  Serial.print(++treffer);
  Serial.print(" ");
  Serial.print(analog_in);
  Serial.println();
  delay(1000);
}
