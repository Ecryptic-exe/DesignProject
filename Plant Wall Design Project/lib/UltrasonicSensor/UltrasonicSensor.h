#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
  private:
    int trigPin;
    int echoPin;
    //Set Water Level Distance in CM
    long emptyTankDistance = 150 ;  //Distance when tank is empty
    long fullTankDistance =  40 ;  //Distance when tank is full (must be greater than 25cm)
    unsigned long previousMillis;
    const unsigned long interval = 1000; // Delay interval in milliseconds

  public:
    UltrasonicSensor(int trigPin, int echoPin);
    void begin();
    void update();
    float getWaterLevel();
};

#endif