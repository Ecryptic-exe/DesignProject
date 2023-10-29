#include "Arduino.h"
#include "SoilSensor.h"

#define TIMEOUT 500UL

const byte moistTemp[] = {0x01, 0x03, 0x00, 0x12, 0x00, 0x02, 0x64, 0x0E};
const byte EC[] = {0x01, 0x03, 0x00, 0x15, 0x00, 0x01, 0x95, 0xCE};
const byte PH[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte NKP[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};

SoilSensor::SoilSensor(int RE_pin, int DE_pin, int Rx_pin, int Tx_pin) : _mod(Rx_pin,Tx_pin) {
   _RE = RE_pin;
   _DE = DE_pin;
   pinMode(_RE, OUTPUT);
   pinMode(_DE, OUTPUT);
   _mod.begin(9600);
}

byte SoilSensor::readMoistTemp() {
   return readSensor(moistTemp);
}

byte SoilSensor::readEC() {
   return readSensor(EC);
}

byte SoilSensor::readPH() {
   return readSensor(PH);
}

byte SoilSensor::readNKP() {
   return readSensor(NKP);
}

byte SoilSensor::readSensor(const byte* command) {
   uint32_t startTime = millis();
   uint8_t values[11];
   uint8_t byteCount = 0;

   while (millis() - startTime <= TIMEOUT) {
      if (byteCount < sizeof(values)) {
         values[byteCount++] = (uint8_t)_mod.read();
         printHexByte(values[byteCount -1]);
      }
   }
   
   Serial.println();
   
   return values[4];
}

void SoilSensor::printHexByte(byte b) {
   Serial.print(b, HEX);
   Serial.print(' ');
}

unsigned short do_crc(unsigned char *ptr, int len){
   unsigned int i;
   unsigned short crc = 0xFFFF;

   while(len--){
      crc ^= *ptr++;
      for (i = 0; i < 8; ++i){
         if (crc & 1){
            crc = (crc >> 1) ^ 0xA001;
         }
         else{
            crc = (crc >> 1);
         }
      }
   }

   return crc;
}