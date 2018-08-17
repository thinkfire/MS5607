#include <Arduino.h>
#include <MS5607.h>
#include <Wire.h>
void ErrorLoop(void);

MS5607 P_SENS;

void setup() {
  Serial.begin(9600);
  if(!P_SENS.begin()){
    Serial.println("MS5607 failed!");
    ErrorLoop();
  }else Serial.println("MS5607 initialise successfully!");
}

void loop() {

  Serial.println("Pressure    - "+String(P_SENS.getPressure())+" mbar");
  Serial.println("Temperature - "+String(P_SENS.getTemperature())+" C");
  delay(5000);
}
