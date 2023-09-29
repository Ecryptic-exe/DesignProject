#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

#include "pinmap.h"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(flowSensor1, INPUT);
  pinMode(flowSensor2, INPUT);
  pinMode(flowSensor3, INPUT);

  pinMode(solenoidValve1, INPUT);
  pinMode(solenoidValve2, INPUT);
  pinMode(solenoidValve3, INPUT);

  pinMode(soilSensor1, INPUT);
  pinMode(soilSensor2, INPUT);
  pinMode(soilSensor3, INPUT);

  pinMode(waterLvSensor, INPUT);

  pinMode(waterPump, INPUT);

  Serial.begin(115200);
  dht.begin();
}

void loop() {

}
