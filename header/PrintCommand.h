#pragma once
#include "Command.h"
#include <string>
class PrintCommand : public Command{
public:
    std::string msg;
    PrintCommand(std::string &s) : msg(s){type = 0;}
    bool validate() override{return true;}
};