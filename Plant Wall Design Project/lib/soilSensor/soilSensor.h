#ifndef SoilSensor_h
#define SoilSensor_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class SoilSensor {

  private:
    void printHexByte(byte b);
    byte readSensor(const byte* command);
    SoftwareSerial _mod;
    int _RE;
    int _DE;

  public:
    SoilSensor(int Rx_pin, int Tx_pin);
    byte readMoistTemp();
    byte readEC();
    byte readPH();
    byte readNKP();
};

#endif
