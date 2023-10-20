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

DHT dht(DHTPIN, DHTTYPE);

msg nanoMsg;

SoilSensor soilSensor1(1,2,soilSensor1Rx,soilSensor1Tx); // RE pin:1 DE pin:2 Rx pin:A1 Tx pin:A2
SoilSensor soilSensor2(3,4,soilSensor2Rx,soilSensor2Tx); // RE pin:3 DE pin:4 Rx pin:A3 Tx pin:A4
SoilSensor soilSensor3(5,6,soilSensor3Rx,soilSensor3Tx); // RE pin:5 DE pin:6 Rx pin:A5 Tx pin:A6

SolenoidValve Valve1(solenoidValve1);
SolenoidValve Valve2(solenoidValve2);
SolenoidValve Valve3(solenoidValve3);

WaterFlowSensor FlowSensor1(flowSensor1, 1000);
WaterFlowSensor FlowSensor2(flowSensor2, 1000);
WaterFlowSensor FlowSensor3(flowSensor3, 1000);

waterPump pump(waterPumpPinA, waterPumpPinB);

void pinSetup(){

};

void readSoilSensor(){  // Sample placeholder
    byte moist1 = soilSensor1.readMoist();
    byte moist2 = soilSensor2.readMoist();
    byte moist3 = soilSensor3.readMoist();

    Serial.print("Moisture Sensor #1: ");
    Serial.println(moist1);

    Serial.print("Moisture Sensor #2: ");
    Serial.println(moist2);

    Serial.print("Moisture Sensor #3: ");
    Serial.println(moist3);
};

/////////////////////////////////////////

void setup() {
  pinSetup();

  dht.begin();

  //Serial.begin(115200);
  nanoMsg.init(&Serial);
}

void loop() {
  if(!nanoMsg.read()){
    return;
  }
}

