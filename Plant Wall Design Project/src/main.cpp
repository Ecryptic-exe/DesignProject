#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <PubSubClient.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <WiFi.h>

#include "DHT.h"

#include "pinmap.h"

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Placeholder";
const char* password = "Placeholder";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

void pinSetup(){
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

/////////////////////////////////////////

void setup() {
  pinSetup();

  Serial.begin(115200);
  dht.begin();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

