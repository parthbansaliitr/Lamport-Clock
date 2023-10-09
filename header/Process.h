#pragma once
#include "Command.h"
#include <vector>
#include "PrintCommand.h"
#include "RecvCommand.h"
#include "SendCommand.h"
#include <type_traits>
#include <variant>
// #include <iomanip>
// using cmd_t = std::variant<PrintCommand, RecvCommand, SendCommand>;
template<typename T>
class Process{
private:
    T name;
    std::vector<Command*>Commands;
public:
    Process(T name) : name(name){ }
    T getName(){
        return name;
    }
    void addCommand(Command* cmd){
        Commands.push_back(cmd);
    }
    int getCmdSz(){
        return Commands.size();
    }
    Command* getCmd(int index){
        if(index>=Commands.size())return nullptr;
        return Commands[index];
    }
};