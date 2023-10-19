#include <Arduino.h>

#ifndef _WATERPUMP_H
#define _WATERPUMP_H


class waterPump{
    private:
    int waterPumpPin;
    int pumpPWM;
    int pwmFreq;
    float minRate;
    float maxRate;

    public:
    waterPump(int waterPumpPin);
    void initializePump();
    void pumpRate(int pumpPWM);
    void startPump();
    void stopPump();
};

#endif


