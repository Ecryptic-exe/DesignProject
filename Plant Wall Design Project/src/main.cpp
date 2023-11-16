#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <PubSubClient.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <WiFi.h>

#include "DHT.h"
#include "flowSensor.h"
#include "msg.h"
#include "soilSensor.h"
#include "solenoidValve.h"
//#include "waterLvSensor.h"
#include "waterPump.h"

#include "pinmap.h"

// DHT dht(DHTPIN, DHTTYPE);

// msg nanoMsg;

SoilSensor soilSensor1(soilSensor1Rx,soilSensor1Tx);
// SoilSensor soilSensor2(soilSensor2Rx,soilSensor2Tx);
// SoilSensor soilSensor3(soilSensor3Rx,soilSensor3Tx);

// SolenoidValve Valve1(solenoidValve1);
// SolenoidValve Valve2(solenoidValve2);
// SolenoidValve Valve3(solenoidValve3);

// WaterFlowSensor FlowSensor1(flowSensor1, 1000);
// WaterFlowSensor FlowSensor2(flowSensor2, 1000);
// WaterFlowSensor FlowSensor3(flowSensor3, 1000);

// waterPump pump(waterPumpPinA, waterPumpPinB);

void pinSetup(){

};

void readSoilSensor1(){  // Sample placeholder
  soilSensor1.readMoistTemp();
  soilSensor1.readEC();
  soilSensor1.readPH();
  soilSensor1.readNKP();
};

/////////////////////////////////////////

void setup() {
  pinSetup();

  Serial.begin(9600);

}

void loop() {
  readSoilSensor1();

}