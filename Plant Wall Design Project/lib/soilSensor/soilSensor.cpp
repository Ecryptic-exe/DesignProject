#include "Arduino.h"
#include "SoilSensor.h"

#define TIMEOUT 500UL

const byte moist[] = {0x01, 0x03, 0x00, 0x12, 0x00, 0x01, 0x24, 0x0F};
const byte temp[] = {0x01, 0x03, 0x00, 0x13, 0x00, 0x01, 0x75, 0xCF};
const byte EC[] = {0x01, 0x03, 0x00, 0x15, 0x00, 0x01, 0x95, 0xCE};
const byte PH[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte N[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};
const byte K[] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xB5, 0xCC};
const byte P[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};

// SoilSensor::SoilSensor(int RE_pin, int DE_pin, int Rx_pin, int Tx_pin) : _mod(Rx_pin,Tx_pin) {
//    _RE = RE_pin;
//    _DE = DE_pin;
//    pinMode(_RE, OUTPUT);
//    pinMode(_DE, OUTPUT);
//    _mod.begin(9600);
// }



SoilSensor::SoilSensor(int Rx_pin, int Tx_pin) : _mod(Rx_pin,Tx_pin) {
   // _RE = RE_pin;
   // _DE = DE_pin;
   // pinMode(_RE, OUTPUT);
   // pinMode(_DE, OUTPUT);
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

byte SoilSensor::readN() {
   return readSensor(N);
}
byte SoilSensor::readK() {
   return readSensor(K);
}

byte SoilSensor::readP() {
   return readSensor(P);
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
   // Serial.print(b, HEX);
   // Serial.print(' ');
   Serial.print((b >> 4) & 0xF, HEX);
   Serial.print(b & 0xF, HEX);
   Serial.print(' ');
}

// unsigned short do_crc(unsigned char *ptr, int len){
//    unsigned int i;
//    unsigned short crc = 0xFFFF;

//    while(len--){
//       crc ^= *ptr++;
//       for (i = 0; i < 8; ++i){
//          if (crc & 1){
//             crc = (crc >> 1) ^ 0xA001;
//          }
//          else{
//             crc = (crc >> 1);
//          }
//       }
//    }

//    return crc;
// }