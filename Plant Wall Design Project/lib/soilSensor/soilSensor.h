#ifndef SOILSENSOR_H
#define SOILSENSOR_H

#include <Arduino.h>

class SoilSensor {
  public:
    SoilSensor(HardwareSerial& serial); // Constructor that takes a reference to a HardwareSerial object
    void begin(); // Initialize the communication with the soil sensor
    float getTemperature(); // Get the soil temperature in Celsius
    float getHumidity(); // Get the soil humidity in percentage
    float getConductivity(); // Get the soil conductivity in mS/cm
    float getpH(); // Get the soil pH
    float getNitrogen(); // Get the soil nitrogen in mg/kg
    float getPhosphorus(); // Get the soil phosphorus in mg/kg
    float getPotassium(); // Get the soil potassium in mg/kg
    unsigned long getLastQueryTime(); // Get the last query time in milliseconds

  private:
    HardwareSerial& _serial; // A reference to the HardwareSerial object
    unsigned long _lastQueryTime; // A variable to store the last query time in milliseconds
    void sendQuery(byte query[], int size); // Send a query to the soil sensor
    byte* readResponse(byte* response, int size); // Read the response from the soil sensor
    float parseData(byte high, byte low, float factor); // Parse the data from two bytes and apply a factor
};

#endif
