#pragma once
#include "Command.h"
#include <string>
class PrintCommand : public Command{
private:
    std::string s;
public:
    PrintCommand(std::string &s) : s(s) {}
    void executeCmd();
};