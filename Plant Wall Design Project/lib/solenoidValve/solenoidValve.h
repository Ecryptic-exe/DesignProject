#include <Arduino.h>

#ifndef SOLENOID_VALVE_H
#define SOLENOID_VALVE_H

class SolenoidValve {
  private:
    uint8_t pin; // #178900
    
  public:
    SolenoidValve(uint8_t pin);
    void initializeValue();
    void valveOpen();
    void valveClose();
};

#endif