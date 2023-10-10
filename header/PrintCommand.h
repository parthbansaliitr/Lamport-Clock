#pragma once
#include "Command.h"
#include <string>
class PrintCommand : public Command{
public:
// private:
    std::string msg;
    PrintCommand(std::string &s) : msg(s){type = 0;}
    void executeCmd();
    bool validate() override{return true;}
};