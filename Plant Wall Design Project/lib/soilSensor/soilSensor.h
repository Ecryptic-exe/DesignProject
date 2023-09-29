#include <Arduino.h>

#ifndef _SOILSENSOR_H
#define _SOILSENSOR_H

class soilSensor{
    private:
        float temperature;
        float humidity;
        float PHValue;
        float nitrogen;
        float phosphorus;
        float potassium;

        unsigned long previousMillis;
        unsigned long interval;

    public:
        soilSensor(int pin, unsigned long intervalMillis);
        float getTemperature();
        float getHumidity();
        float getPHValue();
        float getNitrogen();
        float getPhosphorus();
        float getPotassium();
};

#endif