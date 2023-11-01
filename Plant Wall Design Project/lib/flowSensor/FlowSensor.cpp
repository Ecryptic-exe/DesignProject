#include "Arduino.h"
#include "FlowSensor.h"

FlowSensor* flowSensorInstance;

FlowSensor::FlowSensor(int pin)
{
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH); // Optional Internal Pull-Up
  _flowsensor = pin;
  flowSensorInstance = this;
}

void FlowSensor::flow()
{
  flowSensorInstance->_flow_frequency++;
}

void FlowSensor::setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(_flowsensor), flow, RISING); // Setup Interrupt
  sei(); // Enable interrupts
  _currentTime = millis();
  _cloopTime = _currentTime;
}

void FlowSensor::loop()
{
  _currentTime = millis();
  // Every second, calculate and print litres/minute
  if(_currentTime >= (_cloopTime + 1000))
  {
    _cloopTime = _currentTime; // Updates cloopTime
    // Pulse frequency (Hz) = 11Q, Q is flow rate in L/min.
    _l_min = (_flow_frequency / 11.0); // Pulse frequency / 11Q = flowrate in L/min
    _flow_frequency = 0; // Reset Counter
    Serial.print(_l_min, DEC); // Print litres/minute
    Serial.println(" L/min");
  }
}
