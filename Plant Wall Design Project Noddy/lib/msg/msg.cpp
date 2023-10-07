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
    x_speed = (int) nano->read();
    waterPump = (int) nano->read() != 0x00 ? true : false;
    lifting_status = (int) nano->read();

    return true;
}

int msg::getx_speed(){
    return x_speed;
}

int msg::getLiftingStatus(){
    return lifting_status;
}

bool msg::getWaterPump(){
    return waterPump;
}