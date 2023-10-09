#pragma once
#include "Command.h"
#include <vector>
#include "PrintCommand.h"
#include "RecvCommand.h"
#include "SendCommand.h"
#include "Clock.h"
#include "Message.h"

template<typename T>
class Process{
private:
    T name;
    std::vector<Command*>Commands;
    Clock<int> time;
    Process* blocked;
    int cmdsExecuted;
    std::vector<Message<T>*>msgs;
public:
    Process(T name) : name(name), time(0), cmdsExecuted(0){
        
    }
    T getName(){
        return name;
    }
    void addCommand(Command* cmd){
        Commands.push_back(cmd);
    }
    int getCmdSz(){
        return Commands.size();
    }
    Command* getNextCmd(){
        return Commands[cmdsExecuted];
    }
    void increaseCmd(){cmdsExecuted++;}
    Command* getCmd(int index){
        if(index>=Commands.size())return nullptr;
        return Commands[index];
    }
    bool execute(void* managers);
    bool completed(){
        return cmdsExecuted == Commands.size();
    }
    void addMessage(Message<T>* msg){
        msgs.push_back(msg);
    }
    Process* blocker(){return blocked;}
    void updateBlock(){
        
    }
};