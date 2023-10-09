#pragma once
#include "Command.h"
template<typename T>
class RecvCommand : public Command{
    T name;
    T message;
public:
    RecvCommand(T name, T Message) : name(name), message(message){

    }
    // void execute() override;
};