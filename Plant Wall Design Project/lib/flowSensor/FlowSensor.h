#include <Arduino.h>

#ifndef FLOWSENSOR_H
#define FLOWSENSOR_H

class FlowSensor {

  public:
    FlowSensor(int pin); // constructor
    void begin(); // initialize the sensor
    bool getflowRate(); // get the flowRate in liters
  private:
    int sensorPin; // the pin number of the sensor
    static volatile long pulse; // the number of pulses from the sensor, make it static
    unsigned long lastTime; // the last time the pulse was updated
    float flowRate; // the flowRate in liters
    unsigned long totalMilliLitres = 0;
    unsigned long TargetValue = 30;
    static void increase(); // the interrupt handler function, also static
};

#endif