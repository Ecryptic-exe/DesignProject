#include "solenoidValve.h"

// Constructor
solenoidValve::solenoidValve(uint8_t SOLENOID_PIN1, uint8_t SOLENOID_PIN2, uint8_t SOLENOID_PIN3) {
  this->SOLENOID_PIN1 = SOLENOID_PIN1;
  pinMode(SOLENOID_PIN1, OUTPUT);
  this->SOLENOID_PIN2 = SOLENOID_PIN2;
  pinMode(SOLENOID_PIN2, OUTPUT);
  this->SOLENOID_PIN3 = SOLENOID_PIN3;
  pinMode(SOLENOID_PIN3, OUTPUT);
}

// Initialize the pump
void solenoidValve::initializeValue() {
  // Code to initialize the pump
  valveClose1();
  valveClose2();
  valveClose3();
}

// Start the pump1
void solenoidValve::valveOpen1() {
  // Code to start the pump
  digitalWrite(SOLENOID_PIN1, HIGH);
}
// Stop the pump1
void solenoidValve::valveClose1() {
  // Code to stop the pump
  digitalWrite(SOLENOID_PIN1, LOW);
}

// Start the pump2
void solenoidValve::valveOpen2() {
    // Code to start the pump
    digitalWrite(SOLENOID_PIN2, HIGH);
}
// Stop the pump2
void solenoidValve::valveClose2() {
    // Code to stop the pump
    digitalWrite(SOLENOID_PIN2, LOW);
}

// Start the pump3
void solenoidValve::valveOpen3() {
    // Code to start the pump
    digitalWrite(SOLENOID_PIN3, HIGH);
}
// Stop the pump3
void solenoidValve::valveClose3() {
    // Code to stop the pump
    digitalWrite(SOLENOID_PIN3, LOW);
}
