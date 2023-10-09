#pragma once
#include "Process.h"
#include <vector>
#include <string>
#include <map>
#include "Message.h"
#include <fstream>
// template<typename T>
// class Process;
template<typename T>
class ProcessManager{
private:
    std::vector<Process<T>*>Processes;
    std::vector<int>isExecuted;
    std::map<T, int> idToProcessNumber;
    std::ofstream& out;
public:
    ProcessManager(std::ofstream& out):out(out){

    }
    auto addProcess(T name){
        Process<T>* newProcess = new Process<T>(name);
        Processes.push_back(newProcess);
    }
    void addProcess(Process<T>&& Process){
        Processes.push_back(std::forward(Process));
        idToProcessNumber[Processes.back()->getName()] = Processes.size()-1;
    }
    auto getLastProcess(){
        return Processes.back();
    }
    auto getProcessFromName(T name){
        for(Process<T>* it:Processes){
            if(it->getName() == name)return true;
        }
        return false;
    }
    int getProcessNumber(T name){
        if(idToProcessNumber.find(name) == idToProcessNumber.end())return -1;
        else return idToProcessNumber[name];
    }
    void addMessageToProcessQueue(Message<T>* msg){
        Processes[getProcessNumber(msg->fromId)]->addMessage(msg);
    }
    bool validateProcesses();
    bool execute();
    bool isDeadlocked();
    void PrintDeadlock();
    bool executeProceess(int id);
};