#include "msg.h"

void msg::init(HardwareSerial* serial){ 
    nano = serial;

    nano->begin(115200);
}

bool msg::read(){
    if(!nano->available()){ 
        return false;
    }
    if (nano->read() != start_byte){ 
        return false;
    }

    return true;
}
