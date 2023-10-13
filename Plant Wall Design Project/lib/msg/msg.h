#include <Arduino.h>

#ifndef MSG_H
#define MSG_H

    class msg{
        private:
            uint8_t start_byte = 0xff; 
            HardwareSerial* nano;


            float waterLv = 0;

        public:
            void init(HardwareSerial* serial);

            bool read();

            float getWaterLv(); 

            float getTemperature();
            float getHumidity();
            float getPHValue();
            float getNitrogen();
            float getPhosphorus();
            float getPotassium();

            float getFlowRate();

            void getValveStatus();
            void getPumpStatus();
    };

#endif