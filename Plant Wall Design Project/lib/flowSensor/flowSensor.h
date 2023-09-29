#include <Arduino.h>

#ifndef _FLOWSENSOR_H
#define _FLOWSENSOR_H

class flowSensor{
    private:
    float flowRate;

    public:
    float getFlowRate();
};

#endif