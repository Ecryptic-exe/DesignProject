#include "waterPump.h"

//Drive through PWM Motor Driver

// Constructor
waterPump::waterPump(int waterPumpPin) {
  this->waterPumpPin = waterPumpPin;
  pinMode(waterPumpPin, OUTPUT);

// Percentage
  float minRate = 0.00f;
  float maxRate = 98.00f;

}

// Initialize the pump
void waterPump::initializePump() {
  // Code to initialize the pump
  stopPump();
}

void waterPump::pumpRate(int pumpPWM){
  analogWrite(waterPumpPin, pumpPWM);
}

// Start the pump
void waterPump::startPump() {
  // Code to start the pump
  unsigned rate = constrain(rate, minRate, maxRate); // Ensure rate is within the defined range
  int pwmValue = map(rate, 0, 100, 0, 255); // Map percentage to PWM value
  pumpRate(pwmValue);
}

// Stop the pump
void waterPump::stopPump() {
  // Code to stop the pump
  pumpRate(0);
}