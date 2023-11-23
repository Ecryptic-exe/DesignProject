#include "FlowSensor.h"

// define the static member variable here, outside the class
volatile long FlowSensor::pulse = 0;

FlowSensor::FlowSensor(int pin) {
  sensorPin = pin; // set the pin number
  lastTime = 0; // initialize the last time
  flowRate = 0; // initialize the flowRate
  totalMilliLitres = 0;
}

void FlowSensor::begin() {
  pinMode(sensorPin, INPUT); // set the pin mode
  attachInterrupt(digitalPinToInterrupt(sensorPin), FlowSensor::increase, RISING); // attach the interrupt handler
}

float FlowSensor::getflowRate() {
  if(millis() - lastTime <= 1000){
    flowRate = (pulse * 1000 / 60 / 11); // (Pulse frequency x 1000 mL) / 60 min / 11Q = flowrate in mL/s
    Serial.print(flowRate);
    Serial.println(" mL/s   ");
    lastTime = millis(); // update the last time
    pulse = 0; // reset the pulse
    return flowRate;
  }
}

void FlowSensor::increase() {
  pulse++; // increment the pulse
}