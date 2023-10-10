#pragma once
#include "Command.h"
#include <vector>
#include "PrintCommand.h"
#include "RecvCommand.h"
#include "SendCommand.h"
#include "Clock.h"
#include "Message.h"
#include <iostream>
template<typename T>
class Process{
private:
    T name;
    std::vector<Command*>Commands;
    int cmdsExecuted;
    std::vector<Message<Clock<int>>*>msgs;
public:
    Message<Clock<int>> blockingMsg;
    Process<T>* blocked;
    Clock<int> time;
    Process(T name) : name(name), cmdsExecuted(0),
     blockingMsg() , blocked(nullptr), time(0){
        
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
    void decreaseCmd(){cmdsExecuted--;}
    Command* getCmd(int index){
        if(index>=(int)Commands.size())return nullptr;
        return Commands[index];
    }
    bool execute(void* managers);
    bool completed(){
        return cmdsExecuted == (int)Commands.size();
    }
    void addMessage(Message<Clock<int>>* msg){
        // if(blocked != nullptr && blockingMsg == *msg){
        //     blocked = nullptr;
        //     time.increment();
        //     time.updateClock(msg->time);
        // }
        // else{
            msgs.push_back(msg);
        // }
        
    }
    Process* blocker(){return blocked;}
    void updateBlock(){
        
    }
    bool checkMsgQueue(Message<Clock<int>>msg){
        for(int i = 0;i<(int)msgs.size();i++){
            if(*msgs[i] == msg){
                
                time.updateClock(msgs[i]->time);
                msgs.erase(msgs.begin() + i);
                return true;
            }
        }
        return false;
        
        // return false;
    }
};