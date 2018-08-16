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
  if(P_SENS.startMeasurment()){
    Serial.println("ADC read successful!");
  }else{Serial.println("Error in ADC read!");ErrorLoop();}

  if(P_SENS.readDigitalValue()){
    Serial.println("Digital read successful!");
  }else{Serial.println("Error in digital read!");ErrorLoop();}

  delay(5000);
}

void ErrorLoop(void){
  while (1) {
    Serial.print(".");
    delay(500);
  }
}
