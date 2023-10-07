#include "flowSensor.h"

WaterFlowSensor::WaterFlowSensor(int flowRate1, int flowRate2, int flowRate3,unsigned long intervalMillis)
    : flowRate1(flowRate1), flowRate2(flowRate2), flowRate3(flowRate3), interval(intervalMillis) {
  this->flowRate1 = flowRate1;
  this->flowRate2 = flowRate2;
  this->flowRate3 = flowRate3;
  this->interval = intervalMillis;
}

void WaterFlowSensor::begin() {
    // Initialize the sensor
    pinMode(flowRate1, INPUT);
    pinMode(flowRate2, INPUT);
    pinMode(flowRate3, INPUT);
    previousMillis = 0; 
    int flowRate1 = 0;
    int flowRate2 = 0;
    int flowRate3 = 0;
}

float WaterFlowSensor::readFlowRate(int flowRate1, int flowRate2, int flowRate3) {
    // Read the sensor value and convert it to flow rate
    // Perform necessary calculations to convert sensorValue to flow rate
    int sensorValue1 = analogRead(flowRate1);
    int flowRate1 = sensorValue1 * 11; // Example calculation, adjust as per sensor specifications
    int sensorValue2 = analogRead(flowRate2);
    flowRate2 = sensorValue2 * 11; // Example calculation, adjust as per sensor specifications
    int sensorValue3 = analogRead(flowRate3);
    flowRate3 = sensorValue3 * 11; // Example calculation, adjust as per sensor specifications

  return flowRate1;
  return flowRate2;
  return flowRate3;
}

void WaterFlowSensor::updateSensorValue(){
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Read sensor1 value
    float newS1 = flowRate1;
    if (isnan(newS1)) {
        Serial.println("Failed to read Flowsensor1 value!");
    } else {
        flowRate1 = newS1;
      
      // Print temperature
        Serial.print("Flowsensor1: ");
        Serial.println(flowRate1); 
    }
    
    float newS2 = flowRate2;
    if (isnan(newS2)) {
        Serial.println("Failed to read Flowsensor2 value!");
        } else {
            flowRate2 = newS2;

            // Print temperature
            Serial.print("Flowsensor2: ");
            Serial.println(flowRate2);
        }

    float newS3 = flowRate3;
    if (isnan(newS3)) {
        Serial.println("Failed to read Flowsensor3 value!");
        } else {
            flowRate3 = newS3;

            // Print temperature
            Serial.print("Flowsensor3: ");
            Serial.println(flowRate3);
            }
  }
}