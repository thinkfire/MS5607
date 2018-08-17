/*
  ms5607.h
  TE Connectivity sensor pressure sensor MS5607 library for the Arduino microcontroller
  this library used I2C bus.
*/
//#define MS5607_DEBUG

#define MS5607_ADDR 0X76
#define PROM_READ  0xA0
#define RESET  0x1E
#define OSR 4096
//#define CONV_D1  0x40 //OSR = 256 //calculation time = 0.60 ms
#define CONV_D1 0x48 //OSR = 4096 //calculation time = 9.04 ms
//#define CONV_D2  0x50 //OSR = 256 //calculation time = 0.60 ms
#define CONV_D2 0x58 //OSR=4096 //calculation time = 9.04 ms
#define R_ADC  0X00 //adc read

#include <Arduino.h>

class MS5607
{
  public:
    MS5607();
    char begin();
    float getTemperature(void);
    float getPressure(void);
    
  private:
    unsigned int C1,C2,C3,C4,C5,C6;
    unsigned long DP, DT;
    float dT, TEMP, P;
    float const1, const2, const4, const5, const6;
    int64_t const3;
    int64_t OFF, SENS;

    char resetDevice(void);
    char readCalibration();
    char readUInt_16(char address, unsigned int &value);
    char readBytes(unsigned char *values, char length);
    char startConversion(char CMD);
    char startMeasurment(void);
    char getDigitalValue(void);
    char readDigitalValue(unsigned long &value);
    String ToString(uint64_t x);

};
