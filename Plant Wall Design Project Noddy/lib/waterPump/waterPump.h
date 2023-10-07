#include <Arduino.h>

#ifndef _WATERPUMP_H
#define _WATERPUMP_H


class waterPump{
    private:
    uint8_t waterPumpPin;
    public:
    waterPump(uint8_t waterPumpPin);
    void initializePump();
    void startPump();
    void stopPump();
};

#endif


