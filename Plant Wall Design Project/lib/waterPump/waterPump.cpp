#include "waterPump.h"

// Constructor
waterPump::waterPump(uint8_t waterPumpPin) {
  this->waterPumpPin = waterPumpPin;
  pinMode(waterPumpPin, OUTPUT);
}

// Initialize the pump
void waterPump::initializePump() {
  // Code to initialize the pump
  stopPump();
}

// Start the pump
void waterPump::startPump() {
  // Code to start the pump
  digitalWrite(waterPumpPin, HIGH);
}

// Stop the pump
void waterPump::stopPump() {
  // Code to stop the pump
  digitalWrite(waterPumpPin, LOW);
}
