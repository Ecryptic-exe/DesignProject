#include "msg.h"

void msg::init(HardwareSerial* serial){ 
    nano = serial;

    nano->begin(9600);
}

bool msg::read(){
    if(!nano->available()){ 
        return false;
    }
    if (nano->read() != start_byte){ 
        return false;
    }

    //decoding 
    SolenoidValue1 = (int) nano->read();
    SolenoidValue2 = (int) nano->read();
    SolenoidValue3 = (int) nano->read();
    waterPump = (int) nano->read() != 0x00 ? true : false;
    lifting_status = (int) nano->read();

    return true;
}

bool msg::getSolenoidValue1(){
    return SolenoidValue1;
}

bool msg::getSolenoidValue2(){
    return SolenoidValue2;
}

bool msg::getSolenoidValue3(){
    return SolenoidValue3;
}

int msg::getLiftingStatus(){
    return lifting_status;
}

bool msg::getWaterPump(){
    return waterPump;
}