#pragma once
#include "Clock.h"
#include <string>
template<typename T>
class Message{
public:
    std::string payload;
    T time;
    std::string fromId;
    Message(std::string payload, T&& time, std::string fromId){
        this->payload = payload;
        this->time = std::forward(time);
        this->fromId = fromId;
    }
};