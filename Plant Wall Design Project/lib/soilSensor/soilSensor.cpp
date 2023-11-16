#include "Arduino.h"
#include "SoilSensor.h"

#define TIMEOUT 500UL

const byte moistTemp[] = {0x01,0x03,0x00,0x12,0x00,0x02,0x64,0x0E};
const byte EC[] = {0x01, 0x03, 0x00, 0x15, 0x00, 0x01, 0x95, 0xCE};
const byte PH[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte NKP[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x03, 0x65, 0xCD};

SoilSensor::SoilSensor(int Rx_pin, int Tx_pin) : _mod(Rx_pin,Tx_pin) {
   // _RE = RE_pin;
   // _DE = DE_pin;
   // pinMode(_RE, OUTPUT);
   // pinMode(_DE, OUTPUT);
   _mod.begin(9600);
   Serial.begin(9600);
}

byte SoilSensor::readMoistTemp() {
   // return readSensor(moistTemp);

   byte receivedData[9];

  _mod.write(moistTemp, sizeof(moistTemp));  // Send the query data to the NPK sensor
  delay(1000);  // Wait for 1 second

  _mod.readBytes(receivedData, sizeof(receivedData));  // Read the received data into the receivedData array

  // Parse and print the received data in decimal format
  unsigned int soilTemperature = (receivedData[5] << 8) | receivedData[6];
  unsigned int soilHumidity = (receivedData[3] << 8) | receivedData[4];

  Serial.print("Soil Temperature: ");
  Serial.println((float)soilTemperature / 10.0);
  Serial.print("Soil Humidity: ");
  Serial.println((float)soilHumidity / 10.0);
}

byte SoilSensor::readEC() {
   // return readSensor(EC);
   byte receivedData2[7];

   _mod.write(EC, sizeof(EC));  // Send the query data to the NPK sensor
   delay(1000);  // Wait for 1 second

   _mod.readBytes(receivedData2, sizeof(receivedData2));  // Read the received data into the receivedData array

   // Parse and print the received data in decimal format
   unsigned int soilConductivity = (receivedData2[3] << 8) | receivedData2[4];

   Serial.print("Soil conductivity: ");
   Serial.println((float)soilConductivity / 10.0);
}

byte SoilSensor::readPH() {
   // return readSensor(PH);
   byte receivedData3[7];

  _mod.write(PH, sizeof(PH));  // Send the query data to the NPK sensor
  delay(1000);  // Wait for 1 second

  _mod.readBytes(receivedData3, sizeof(receivedData3));  // Read the received data into the receivedData array

  // Parse and print the received data in decimal format
  unsigned int soilpH = (receivedData3[3] << 8) | receivedData3[4];

  Serial.print("Soil pH: ");
  Serial.println((float)soilpH / 100.0);


}

byte SoilSensor::readNKP() {
   // return readSensor(NKP);
   byte receivedData4[11];

  _mod.write(NKP, sizeof(NKP));  // Send the query data to the NPK sensor
  delay(1000);  // Wait for 1 second

  _mod.readBytes(receivedData4, sizeof(receivedData4));  // Read the received data into the receivedData array

  // Parse and print the received data in decimal format
  unsigned int soilNitrogen = (receivedData4[3] << 8) | receivedData4[4];
  unsigned int soilPhosphorus = (receivedData4[5] << 8) | receivedData4[6];
  unsigned int soilPotassium = (receivedData4[7] << 8) | receivedData4[8];

  Serial.print("Soil Nitrogen: ");
  Serial.println((float)soilNitrogen / 10.0);
  Serial.print("Soil Phosphorus: ");
  Serial.println((float)soilPhosphorus / 10.0);
  Serial.print("Soil Potassium: ");
  Serial.println((float)soilPotassium / 10.0);

}

// byte SoilSensor::readSensor(const byte* command) {
//    uint32_t startTime = millis();
//    uint8_t values[11];
//    uint8_t byteCount = 0;

//    while (millis() - startTime <= TIMEOUT) {
//       if (byteCount < sizeof(values)) {
//          values[byteCount++] = (uint8_t)_mod.read();
//          printHexByte(values[byteCount -1]);
//       }
//    }
//    Serial.println();
   
//    return values[4];
// }

// void SoilSensor::printHexByte(byte b) {
//    // Serial.print(b, HEX);
//    // Serial.print(' ');
//    Serial.print((b >> 4) & 0xF, HEX);
//    Serial.print(b & 0xF, HEX);
//    Serial.print(' ');
// }

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