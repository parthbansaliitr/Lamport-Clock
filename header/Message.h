#pragma once
#include "Clock.h"
#include <string>
template<typename T>
class Message{
public:
    std::string payload;
    T time;
    std::string fromId;
    Message(){
        // time(0);
        payload = "";
        fromId = "";
    }
    Message(std::string payload, T time, std::string fromId){
        this->payload = payload;
        this->time = time;
        this->fromId = fromId;
    }
    bool operator==(const Message<T>& msg){
        return ((payload == msg.payload) && (fromId == msg.fromId));
    }
};