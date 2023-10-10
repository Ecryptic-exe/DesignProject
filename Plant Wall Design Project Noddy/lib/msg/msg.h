#include <Arduino.h>

#ifndef MSG_H
#define MSG_H

    class msg{
        private:
            uint8_t start_byte = 0xff; 
            HardwareSerial* nano;

            bool waterPump = false; 
            bool SolenoidValue1 = false;
            bool SolenoidValue2 = false;
            bool SolenoidValue3 = false;
            int lifting_status = 0;

        public:
            void init(HardwareSerial* serial);

            bool read();
            bool getWaterPump(); 
            bool getSolenoidValue1(); 
            bool getSolenoidValue2();
            bool getSolenoidValue3();
            int getLiftingStatus();

           
    };

#endif