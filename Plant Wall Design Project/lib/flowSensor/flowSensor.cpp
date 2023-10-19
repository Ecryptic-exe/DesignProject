#include "flowSensor.h"

WaterFlowSensor::WaterFlowSensor(int flowRate, unsigned long intervalMillis)
    : flowRate(flowRate), interval(intervalMillis) {
  this->flowRate = flowRate;
  this->interval = intervalMillis;
}

void WaterFlowSensor::begin() {
    // Initialize the sensor
    pinMode(flowRate, INPUT);
    previousMillis = 0; 
    int flowRate = 0;
}

float WaterFlowSensor::readFlowRate(int flowRate) {
    // Read the sensor value and convert it to flow rate
    // Perform necessary calculations to convert sensorValue to flow rate
    int sensorValue = analogRead(flowRate);
    flowRate = sensorValue * 11; // Example calculation, adjust as per sensor specifications

  return flowRate;
}

void WaterFlowSensor::updateSensorValue(){
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Read sensor value
    float newS = flowRate;
    if (isnan(newS)) {
        Serial.println("Failed to read FlowSensor value!");
    } else {
        flowRate = newS;
      
      // Print temperature
        Serial.print("Flowsensor: ");
        Serial.println(flowRate); 
    }
  }
}