#include <Arduino.h>
#include <MS5607.h>
#include <Wire.h>

MS5607 P_SENS;

void setup() {
  Serial.begin(9600);
  if(P_SENS.begin()){
    Serial.println("MS5607 failed!");
    while (1) {
      Serial.print(".");
    }
  }else Serial.println("MS5607 initialise successfully!");
}

void loop() {
    // put your main code here, to run repeatedly:
}
