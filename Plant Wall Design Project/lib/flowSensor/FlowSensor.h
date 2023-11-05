#ifndef FLOWSENSOR_H
#define FLOWSENSOR_H

#include <Arduino.h>

class FlowSensor {
  public:
    FlowSensor(int pin); // constructor
    void begin(); // initialize the sensor
    void getmL_min(); // get the mL_min in liters
  private:
    int sensorPin; // the pin number of the sensor
    static volatile long pulse; // the number of pulses from the sensor, make it static
    unsigned long lastTime; // the last time the pulse was updated
    float mL_min; // the mL_min in liters
    static void increase(); // the interrupt handler function, also static
};

#endif
