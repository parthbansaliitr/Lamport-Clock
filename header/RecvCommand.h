#pragma once
#include "Command.h"
template<typename T>
class RecvCommand : public Command{
public:
    T name;
    T message;
    RecvCommand(T name, T Message) : name(name), message(Message){
        type = 1;
    }
};