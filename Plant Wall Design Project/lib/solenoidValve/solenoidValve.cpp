#include "SolenoidValve.h"

SolenoidValve::SolenoidValve(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void SolenoidValve::initializeValue() {
  valveClose();
}

void SolenoidValve::valveOpen() {
  digitalWrite(_pin, HIGH);
}

void SolenoidValve::valveClose() {
  digitalWrite(_pin, LOW);
}