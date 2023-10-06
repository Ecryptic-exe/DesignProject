#include <Arduino.h>

#ifndef _SOLENOIDVALVE_H
#define _SOLENOIDVALVE_H

class solenoidValve{
    private:
    bool valveIsOpen;

    public:
    void valveOpen();
    void valveClose();
    void getValveStatus();

};

#endif
