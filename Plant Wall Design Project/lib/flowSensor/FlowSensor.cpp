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

void FlowSensor::getflowRate() {
  if (millis() - lastTime > 1000) { // update the flowRate every half second
    flowRate = (pulse * 1000 / 11); // (Pulse frequency x 1000 mL) / 11Q = flowrate in mL/min
    //flowRate = (pulse * 60 / 11); // (Pulse frequency x 60 min) / 11Q = flowrate in L/hour
    Serial.print(flowRate);
    Serial.println(" mL/min   ");
    //Serial.print(" L/h    ");
    lastTime = millis(); // update the last time

    totalMilliLitres += flowRate;
    // Print the cumulative total of litres flowed since starting
    Serial.print("Output Liquid Quantity: ");        
    Serial.print(totalMilliLitres);
    Serial.println("mL");     
        
    if (totalMilliLitres > 40)
    {
      Serial.println("valve low");
    }

    pulse = 0; // reset the pulse
    
  }
}

void FlowSensor::increase() {
  pulse++; // increment the pulse
}
