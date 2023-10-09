#pragma once
#include "Command.h"
#include <vector>
template <typename T>
class SendCommand : public Command{
private:
    std::vector<T> ids;
    T message;
public:
    SendCommand(std::vector<T> ids, T message) : ids(ids), message(message){
        
    }
    // void execute();
};