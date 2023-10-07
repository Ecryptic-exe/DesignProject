#include <Arduino.h>

#ifndef MSG_H
#define MSG_H

    class msg{
        private:
            uint8_t start_byte = 0xff; 
            HardwareSerial* nano;

            bool waterPump = false; 
            int x_speed = 0;
            int lifting_status = 0;

        public:
            void init(HardwareSerial* serial);

            bool read();
            bool getWaterPump(); 
            int getx_speed(); 
            int getLiftingStatus();

           
    };

#endif