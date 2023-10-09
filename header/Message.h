#pragma once
#include "Clock.h"
#include <string>
template<typename T>
class Message{
private:
    string payload;
    T time;
    string fromId;
public:
    Message(string payload, T&& time, string fromId){
        this->payload = payload;
        this->time = std::forward(time);
        this->fromId = fromId;
    }
};