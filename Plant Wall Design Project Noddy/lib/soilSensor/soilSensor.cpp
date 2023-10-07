#include "Arduino.h"
#include "SoilSensor.h"

#define TIMEOUT 500UL

const byte moist[] = {0x01, 0x03, 0x08, 0x02, 0x92, 0x57, 0xB6};
const byte temp[] = {0x01, 0x03, 0x08, 0xFF, 0x9B, 0x57, 0xB6};
const byte EC[] = {0x01, 0x03, 0x08, 0x03, 0xE8, 0x57, 0xB6};
const byte PH[] = {0x01, 0x03, 0x08, 0x00, 0x38, 0x57, 0xB6};

SoilSensor::SoilSensor(int RE_pin, int DE_pin, int Rx_pin, int Tx_pin) : _mod(Rx_pin,Tx_pin) {
   _RE = RE_pin;
   _DE = DE_pin;
   pinMode(_RE, OUTPUT);
   pinMode(_DE, OUTPUT);
   _mod.begin(9600);
}

byte SoilSensor::readMoist() {
   return readSensor(moist);
}

byte SoilSensor::readTemp() {
   return readSensor(temp);
}

byte SoilSensor::readEC() {
   return readSensor(EC);
}

byte SoilSensor::readPH() {
   return readSensor(PH);
}

byte SoilSensor::readSensor(const byte* command) {
   uint32_t startTime = millis();
   uint8_t values[11];
   uint8_t byteCount = 0;

   digitalWrite(_DE,HIGH);
   digitalWrite(_RE,HIGH);
   delay(10);
   _mod.write(command,sizeof(command));
   _mod.flush();
   digitalWrite(_DE,LOW);
   digitalWrite(_RE,LOW);

   while (millis() - startTime <= TIMEOUT) {
      if (_mod.available() && byteCount < sizeof(values)) {
         values[byteCount++] = _mod.read();
         printHexByte(values[byteCount -1]);
      }
   }
   
   Serial.println();
   
   return values[4];
}

void SoilSensor::printHexByte(byte b) {
   Serial.print((b >> 4) & 0xF, HEX);
   Serial.print(b & 0xF, HEX);
   Serial.print(' ');
}
