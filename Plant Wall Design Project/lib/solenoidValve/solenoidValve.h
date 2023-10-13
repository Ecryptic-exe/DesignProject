#include <Arduino.h>

#ifndef _SOLENOIDVALVE_H
#define _SOLENOIDVALVE_H

class solenoidValve{
    private:
    uint8_t SOLENOID_PIN1;
    uint8_t SOLENOID_PIN2;
    uint8_t SOLENOID_PIN3;
    public:
    solenoidValve(uint8_t SOLENOID_PIN1, uint8_t SOLENOID_PIN2, uint8_t SOLENOID_PIN3);
    void initializeValue();
    void valveOpen1();
    void valveClose1();
    void valveOpen2();
    void valveClose2();
    void valveOpen3();
    void valveClose3();
};

#endif
