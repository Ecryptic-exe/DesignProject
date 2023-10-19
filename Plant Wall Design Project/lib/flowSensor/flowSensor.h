#include <Arduino.h>

#ifndef _FLOWSENSOR_H
#define _FLOWSENSOR_H

class WaterFlowSensor {
private:
  int flowRate;
  unsigned long previousMillis;
  unsigned long interval = 1000;

public:
    WaterFlowSensor(int flowRate,unsigned long intervalMillis);
    void updateSensorValue();
    void begin();
    float readFlowRate(int flowRate);
};

#endif