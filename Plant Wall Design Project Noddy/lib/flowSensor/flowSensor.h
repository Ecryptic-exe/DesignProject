#include <Arduino.h>

#ifndef _FLOWSENSOR_H
#define _FLOWSENSOR_H

class WaterFlowSensor {
private:
  int flowRate1;
  int flowRate2;
  int flowRate3;
  unsigned long previousMillis;
  unsigned long interval = 1000;
  int previousMillis = 0;

public:
    WaterFlowSensor(int flowRate1, int flowRate2, int flowRate3,unsigned long intervalMillis);
    void updateSensorValue();
    void begin();
    float readFlowRate(int flowRate1, int flowRate2, int flowRate3);
};

#endif