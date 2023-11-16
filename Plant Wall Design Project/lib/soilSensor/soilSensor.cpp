#include "SoilSensor.h"

SoilSensor::SoilSensor(HardwareSerial& serial) : _serial(serial) {
  // Initialize the reference to the HardwareSerial object
}

void SoilSensor::begin() {
  // Initialize the communication with the soil sensor
  _serial.begin(9600); // This should work now
}

void SoilSensor::sendQuery(byte query[], int size) {
  // Send a query to the soil sensor
  _serial.write(query, size);
  //delay(1000); // Wait for 1 second
  // Instead of using delay, use a variable to store the current time
  _lastQueryTime = millis(); // Get the current time in milliseconds
}

byte* SoilSensor::readResponse(byte *response, int size) {
  // Read the response from the soil sensor
  // Check if enough time has passed since the last query
  if (millis() - _lastQueryTime >= 1000) {
    // If yes, read the response
    _serial.readBytes(&response, size);
  }

  return response;
}

float SoilSensor::parseData(byte high, byte low, float factor) {
  // Parse the data from two bytes and apply a factor
  int16_t data = ((int16_t)high << 8) | low;
  return (float)data / factor;
}

float SoilSensor::getTemperature() {
  // Get the soil temperature in Celsius
  byte temp[] = {0x01,0x03,0x00,0x12,0x00,0x02,0x64,0x0e}; //temp
  byte* receivedData[9];
  sendQuery(temp, sizeof(temp)); // Send the query data to the soil sensor
  receivedData = readResponse(receivedData, sizeof(receivedData)); // Read the received data into the receivedData array
  return parseData(receivedData[5], receivedData[6], 10.0); // Parse and return the data
}

float SoilSensor::getHumidity() {
  // Get the soil humidity in percentage
  byte temp[] = {0x01,0x03,0x00,0x12,0x00,0x02,0x64,0x0e}; //temp
  byte receivedData[9];
  sendQuery(temp, sizeof(temp)); // Send the query data to the soil sensor
  readResponse(receivedData, sizeof(receivedData)); // Read the received data into the receivedData array
  return parseData(receivedData[3], receivedData[4], 10.0); // Parse and return the data
}

float SoilSensor::getConductivity() {
  // Get the soil conductivity in mS/cm
  byte cond[] = {0x01,0x03,0x00,0x15,0x00,0x01,0x95,0xce}; 
  byte receivedData2[7];
  sendQuery(cond, sizeof(cond)); // Send the query data to the soil sensor
  readResponse(receivedData2, sizeof(receivedData2)); // Read the received data into the receivedData array
  return parseData(receivedData2[3], receivedData2[4], 1.0); // Parse and return the data
}

float SoilSensor::getpH() {
  // Get the soil pH
  byte pH[] = {0x01,0x03,0x00,0x06,0x00,0x01,0x64,0x0b}; 
  byte receivedData3[7];
  sendQuery(pH, sizeof(pH)); // Send the query data to the soil sensor
  readResponse(receivedData3, sizeof(receivedData3)); // Read the received data into the receivedData array
  return parseData(receivedData3[3], receivedData3[4], 100.0); // Parse and return the data
}

float SoilSensor::getNitrogen() {
  // Get the soil nitrogen in mg/kg
  byte nitrogen[] = {0x01,0x03,0x00,0x1E,0x00,0x03,0x65,0xcd}; 
  byte receivedData4[11];
  sendQuery(nitrogen, sizeof(nitrogen)); // Send the query data to the soil sensor
  readResponse(receivedData4, sizeof(receivedData4)); // Read the received data into the receivedData array
  return parseData(receivedData4[3], receivedData4[4], 1.0); // Parse and return the data
}

float SoilSensor::getPhosphorus() {
  // Get the soil phosphorus in mg/kg
  byte nitrogen[] = {0x01,0x03,0x00,0x1E,0x00,0x03,0x65,0xcd}; 
  byte receivedData4[11];
  sendQuery(nitrogen, sizeof(nitrogen)); // Send the query data to the soil sensor
  readResponse(receivedData4, sizeof(receivedData4)); // Read the received data into the receivedData array
  return parseData(receivedData4[5], receivedData4[6], 1.0); // Parse and return the data
}

float SoilSensor::getPotassium() {
  // Get the soil potassium in mg/kg
  byte nitrogen[] = {0x01,0x03,0x00,0x1E,0x00,0x03,0x65,0xcd}; 
  byte receivedData4[11];
  sendQuery(nitrogen, sizeof(nitrogen)); // Send the query data to the soil sensor
  readResponse(receivedData4, sizeof(receivedData4)); // Read the received data into the receivedData array
  return parseData(receivedData4[7], receivedData4[8], 1.0); // Parse and return the data
}
unsigned long SoilSensor::getLastQueryTime() {
  // Return the value of the _lastQueryTime attribute
  return _lastQueryTime;
}