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
    // bool validate(ProcessManager<T>* manager){
    //     for(auto i:ids){
    //         if(manager->getProcessNumber)
    //     }
    // }
    // void execute();
};