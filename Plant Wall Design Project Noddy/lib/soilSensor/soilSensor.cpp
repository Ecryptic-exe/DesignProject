#include "soilSensor.h"
#include "Arduino.h"
#include "SoftwareSerial.h"

SoilSensor::SoilSensor(int rxPin, int txPin) : _RS485Serial(rxPin, txPin) {
  _RS485Serial.begin(9600);
}

float SoilSensor::readTemperature() {
  // Send request to sensor
  // Read response
  // Convert response to temperature
  // Return temperature
}

float SoilSensor::readMoisture() {
  // Send request to sensor
  // Read response
  // Convert response to moisture level
  // Return moisture level
}
