#pragma once
#include "Command.h"
#include <vector>
#include "ProcessManager.h"
template <typename T>
class SendCommand : public Command{
// private:
public:
    std::vector<T> ids;
    T message;
    SendCommand(std::vector<T> ids, T message) : ids(ids), message(message){
        type = 2;
    }
};