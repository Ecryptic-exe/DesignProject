#include "FlowSensor.h"

// define the static member variable here, outside the class
volatile long FlowSensor::pulse = 0;

FlowSensor::FlowSensor(int pin) {
  sensorPin = pin; // set the pin number
  lastTime = 0; // initialize the last time
  mL_min = 0; // initialize the mL_min
}

void FlowSensor::begin() {
  pinMode(sensorPin, INPUT); // set the pin mode
  attachInterrupt(digitalPinToInterrupt(sensorPin), FlowSensor::increase, RISING); // attach the interrupt handler
}

void FlowSensor::getmL_min() {
  if (millis() - lastTime > 500) { // update the mL_min every half second
    mL_min = (pulse * 1000 / 11); // (Pulse frequency x 1000 mL) / 11Q = flowrate in mL/min
    //mL_min = (pulse * 60 / 11); // (Pulse frequency x 60 min) / 11Q = flowrate in L/hour
    Serial.print(mL_min);
    Serial.println(" mL/min   ");
    //Serial.print(" L/h    ");

    pulse = 0; // reset the pulse
    lastTime = millis(); // update the last time
  }
}

void FlowSensor::increase() {
  pulse++; // increment the pulse
}
