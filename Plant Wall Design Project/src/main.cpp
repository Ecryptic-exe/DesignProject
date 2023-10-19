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

const char* ssid = "Placeholder";
const char* password = "Placeholder";

const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

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

waterPump pump(_waterPump);

void pinSetup(){

};

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

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

