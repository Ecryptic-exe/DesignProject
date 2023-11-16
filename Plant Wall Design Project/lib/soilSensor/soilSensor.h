#ifndef SOILSENSOR_H
#define SOILSENSOR_H

#include <Arduino.h>

class SoilSensor {
  public:
    SoilSensor(HardwareSerial& serial); // Change the type of the parameter from Stream& to HardwareSerial&
    void begin(); // Initialize the communication with the soil sensor
    float getTemperature(); // Get the soil temperature in Celsius
    float getHumidity(); // Get the soil humidity in percentage
    float getConductivity(); // Get the soil conductivity in mS/cm
    float getpH(); // Get the soil pH
    float getNitrogen(); // Get the soil nitrogen in mg/kg
    float getPhosphorus(); // Get the soil phosphorus in mg/kg
    float getPotassium(); // Get the soil potassium in mg/kg
  private:
    HardwareSerial& _serial; // Change the type of the attribute from Stream& to HardwareSerial&
    void sendQuery(byte query[], int size); // Send a query to the soil sensor
    void readResponse(byte response[], int size); // Read the response from the soil sensor
    float parseData(byte high, byte low, float factor); // Parse the data from two bytes and apply a factor
};

#endif
