#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

#include "DHT.h"
#include "FlowSensor.h"
#include "msg.h"
#include "soilSensor.h"
#include "solenoidValve.h"
//#include "waterLvSensor.h"
#include "UltrasonicSensor.h"
#include "waterPump.h"

#include "pinmap.h"

FlowSensor flowSensor(FlowSensor1);


// msg nanoMsg;

// SoilSensor soilSensor1(soilSensor1Rx,soilSensor1Tx); // RE pin:1 DE pin:2 Rx pin:A1 Tx pin:A2
// SoilSensor soilSensor2(soilSensor2Rx,soilSensor2Tx); // RE pin:3 DE pin:4 Rx pin:A3 Tx pin:A4
// SoilSensor soilSensor3(soilSensor3Rx,soilSensor3Tx); // RE pin:5 DE pin:6 Rx pin:A5 Tx pin:A6

SolenoidValve Valve1(solenoidValve1);
// SolenoidValve Valve2(solenoidValve2);
// SolenoidValve Valve3(solenoidValve3);

// waterPump pump(waterPumpPinA, waterPumpPinB);
// UltrasonicSensor waterLevelSensor(trigPin, echoPin);

void pinSetup(){

};

// void readSoilSensor(){  // Sample placeholder
//     byte moist1 = soilSensor1.readMoist();
//     byte moist2 = soilSensor2.readMoist();
//     byte moist3 = soilSensor3.readMoist();

//     Serial.print("Moisture Sensor #1: ");
//     Serial.println(moist1);

//     Serial.print("Moisture Sensor #2: ");
//     Serial.println(moist2);

//     Serial.print("Moisture Sensor #3: ");
//     Serial.println(moist3);
// };

void valveInit(){
  // Valve1.initializeValve();
  // Valve2.initializeValve();
  // Valve3.initializeValve();
}

void testValve(){
  Valve1.valveClose();
  // Valve2.valveClose();
  // Valve3.valveClose();
  delay(3000);
  Valve1.valveOpen();
  // Valve2.valveOpen();
  // Valve3.valveOpen();
  delay(3000);
}
/////////////////////////////////////////

void setup() {
  Serial.begin(9600);

  flowSensor.begin();
  pinSetup();

  // waterLevelSensor.begin();// Configure ultrasonic sensor

  // valveInit(); // Configure solenoid valve


  //nanoMsg.init(&Serial);

  // pump.initializePump(); // Initialize the pump

}

void loop() {

  //flowsenor
  flowSensor.getflowRate();

  //ultrasonic
  // waterLevelSensor.update();

  //waterPump
  // pump.pumpRate(90);

  //solenoid valve
  // testValve();

  // if(!nanoMsg.read()){
  //   return; 
  // }
}

