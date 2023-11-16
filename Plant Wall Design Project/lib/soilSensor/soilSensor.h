#ifndef SoilSensor_h
#define SoilSensor_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class SoilSensor {

  private:
    void printHexByte(byte b);
    byte readSensor(const byte* command);
    SoftwareSerial _mod;
    // int _RE;
    // int _DE;

  public:
    // SoilSensor(int RE_pin, int DE_pin, int Rx_pin, int Tx_pin);
    SoilSensor(int Rx_pin, int Tx_pin);
    byte readMoist();
    byte readTemp();
    byte readEC();
    byte readPH();
    byte readN();
    byte readK();
    byte readP();
};

#endif
