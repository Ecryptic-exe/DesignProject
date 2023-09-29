#include "dht22.h"
#include <Arduino.h>

DHTSensor::DHTSensor(int pin, int dhtType, unsigned long intervalMillis)
  : dht(pin, dhtType), interval(intervalMillis) {}

void DHTSensor::initialize() {
  dht.begin();
  previousMillis = 0;
  temperature = 0;
  humidity = 0;
}

void DHTSensor::update() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float newT = dht.readTemperature();
    if (isnan(newT)) {
      Serial.println("Failed to read temperature from DHT sensor!");
    }
    else {
      temperature = newT;
      Serial.print("Temp:");
      Serial.print(temperature);
      Serial.print("°C");
      Serial.print('\n');
    }
    float newH = dht.readHumidity();
    if (isnan(newH)) {
      Serial.println("Failed to read humidity from DHT sensor!");
    }
    else {
      humidity = newH;
      Serial.print("Humidity:");
      Serial.print(humidity);
      Serial.print("%");
      Serial.print('\n');
    }
  }
}

float DHTSensor::getTemperature() {
  return temperature;
}

float DHTSensor::getHumidity() {
  return humidity;
}