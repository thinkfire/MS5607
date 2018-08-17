/*
  ms5607.h
  TE Connectivity sensor pressure sensor MS5607 library for the Arduino microcontroller
  this library used I2C bus.
*/
#define MS5607_ADDR 0X76
#define PROM_READ  0xA0
#define RESET  0x1E
#define CONV_D1  0x40 //OSR = 256 //calculation time = 0.60 ms
//#define CONV_D1 0x48 //OSR = 4096 //calculation time = 9.04 ms
#define CONV_D2  0x50 //OSR = 256 //calculation time = 0.60 ms
//#define CONV_D2 0x58 //OSR=4096 //calculation time = 9.04 ms
#define R_ADC  0X00 //adc read

#include <Arduino.h>

class MS5607
{
  public:
    MS5607();
    char begin();
    char getTemperature(void);
    char getPressure(void);
    char readDigitalValue(void);


  private:
    unsigned int C1,C2,C3,C4,C5,C6;
    unsigned long DP, DT;
    long dT, TEMP;
    double OFF, SENS, P;

    char readCalibration();
    char resetDevice(void);
    char readDigitalValue(unsigned long &value);
    char startMeasurment(void);
    //char readDigitalValue(void);
    char readUInt_16(char address, unsigned int &value);
    char readUInt_32(char address, unsigned long &value);
    char readBytes(unsigned char *values, char length);
    char writeBytes(unsigned char *values, char length);


};
