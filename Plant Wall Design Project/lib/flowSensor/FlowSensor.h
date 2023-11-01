#ifndef FlowSensor_h
#define FlowSensor_h

#include "Arduino.h"

class FlowSensor
{
  public:
    FlowSensor(int pin);
    static void flow();
    void setup();
    void loop();
  private:
    volatile int _flow_frequency;
    float _l_min;
    unsigned char _flowsensor;
    unsigned long _currentTime;
    unsigned long _cloopTime;
};

#endif
