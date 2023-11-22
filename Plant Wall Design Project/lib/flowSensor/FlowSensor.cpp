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

bool FlowSensor::getflowRate() {
  if (totalMilliLitres < TargetValue) // 30mL target value
    {
      if(millis() - lastTime <= 1000){

      // update the flowRate every second
      Serial.println("valve high");
      //Valve1.valveOpen();

      flowRate = (pulse * 1000 / 60 / 11); // (Pulse frequency x 1000 mL) / 60 min / 11Q = flowrate in mL/s
      //flowRate = (pulse * 60 / 11); // (Pulse frequency x 60 min) / 11Q = flowrate in L/hour

      Serial.print(flowRate);
      Serial.println(" mL/s   ");
      //Serial.print(" L/h    ");
      lastTime = millis(); // update the last time

      //calculate volume
      totalMilliLitres += flowRate;
      // Print the cumulative total of litres flowed since starting
      Serial.print("Output Liquid Quantity: ");        
      Serial.print(totalMilliLitres);
      Serial.println("mL");     

      pulse = 0; // reset the pulse
      
      return false;
      }
    }
  else if (totalMilliLitres >= TargetValue) // 30mL
  {
    Serial.println("valve low");
    return true;
    // reset the value and timer
    lastTime = 0;
    flowRate = 0;
    totalMilliLitres = 0;
    pulse = 0;      
  }
}

void FlowSensor::increase() {
  pulse++; // increment the pulse
}