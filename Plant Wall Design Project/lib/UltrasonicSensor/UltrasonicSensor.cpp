#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  previousMillis = 0;
}

void UltrasonicSensor::begin() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void UltrasonicSensor::update() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    long t = 0, h = 0, hp = 0; // duration is t, height is h, height percentage is hp
    
    // Transmitting pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Waiting for pulse
    t = pulseIn(echoPin, HIGH);

    // Calculating distance
    h = t * 0.034 / 2; // h=t/58

    h = h - fullTankDistance;  // offset correction
    h = emptyTankDistance - h;  // water height, 0 - 50 cm

    // distance in %, 0-100 %
    hp = h/(emptyTankDistance-fullTankDistance)*100;

    // Sending to computer
    // Serial.print(hp);
    // Serial.print(" cm");
    Serial.print(hp);
    Serial.print("%");
    Serial.print("\n");

    // Checking water level
    if (hp >= 100) {
      Serial.println("Full");
    } else if (hp <= 15) {
      Serial.println("Almost Empty, need to add water");
    }
  }
}

float UltrasonicSensor::getWaterLevel() {
  // Implement the water level calculation if needed
  return 0.0;  // Replace with the actual water level calculation
}