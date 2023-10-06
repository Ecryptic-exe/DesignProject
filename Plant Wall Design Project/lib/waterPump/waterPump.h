#include <Arduino.h>

#ifndef _WATERPUMP_H
#define _WATERPUMP_H

class waterPump{
    private:

    public:
    void pumpOpen();
    void pumpClose();
    void getPumpStatus();

};

#endif