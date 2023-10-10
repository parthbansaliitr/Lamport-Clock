#include "ProcessManager.h"
#include <iostream>
template<typename T>
bool ProcessManager<T>::validateProcesses(){
    for(Process<T>* p:Processes){
        int sz = p->getCmdSz();
        for(int i = 0;i<sz;i++){
            Command* cmdi = p->getCmd(i);
            if(cmdi == nullptr)return false;
            if(cmdi->whatType() == 0){
                // PrintCommand* cmd = (PrintCommand*)(cmdi);
            }
            else if(cmdi->whatType() == 1){
                RecvCommand<T>* cmd = (RecvCommand<T>*)(cmdi);
                if(getProcessNumber(cmd->name) == -1)return false;
            }
            else if(cmdi->whatType() == 2){
                SendCommand<T>* cmd = (SendCommand<T>*)(cmdi);
                for(auto i:cmd->ids){
                    if(getProcessNumber(i) == -1)return false;
                }
            }
            else {
                throw std::runtime_error("Not a command Type\n");
            }
        }
    }
    return true;
}

template<typename T>
bool ProcessManager<T>::execute(){
    int exec = 0;
    while(Processes.size() != 0){
        if(isDeadlocked()){
            PrintDeadlock();
            // throw std::runtime_error("Deadlocked Found");
            return false;
        }
        exec%=Processes.size();
        // Processes[exec]->execute();
        T name1 = Processes[exec]->getName();
        executeProceess(exec);
        exec = getProcessNumber(name1);
        if(Processes[exec]->completed()){
            idToProcessNumber.erase(Processes[exec]->getName());
            Processes.erase(Processes.begin()+exec);
            for(int i = 0;i<(int)Processes.size();i++){idToProcessNumber[Processes[i]->getName()] = i;};
            exec--;
        }
        exec++;
    }
    return true;
}
template<typename T>
bool ProcessManager<T>::isDeadlocked(){
    for(int i = 0;i<(int)Processes.size();i++){
        if(Processes[i]->blocked == nullptr){
            return false;
        }
    }
    return true;
}
template<typename T>
void ProcessManager<T>::PrintDeadlock(){
    for(Process<T>* p: Processes){
        if(getProcessNumber(p->blockingMsg.fromId) == -1){
            out << "Process " << p->blockingMsg.fromId <<  " Never Sent the message " << p->blockingMsg.payload << "\n";
            return;
        }
    }
    out << "These processes are in deadlocked:\n";
    for(Process<T>* p: Processes){
        if(getProcessNumber(p->blockingMsg.fromId) == -1){
            out << "Process " << p->blockingMsg.fromId <<  " Never Sent this message\n";
            return;
        }
        out << p->getName() << " waiting for " << p->blocked->getName() << "\n";
    } 
}
template<typename T>
bool ProcessManager<T>::executeProceess(int id){
    if(Processes[id]->blocker() != nullptr){
        return false;
    }
    Command* cmdi = Processes[id]->getNextCmd();
    if(cmdi->whatType() == 0){
        PrintCommand* cmd = (PrintCommand*)(cmdi);
        Processes[id]->time.increment();
        out << "ProcessName: " << Processes[id]->getName() << " ClockValue: " << Processes[id]->time << " PrintingMsg: " << cmd->msg << "\n";
    }
    else if(cmdi->whatType() == 1){
        RecvCommand<T>* cmd = (RecvCommand<T>*)(cmdi);
        if(Processes[id]->checkMsgQueue(*(new Message(cmd->message,Clock<int>(0), cmd->name)))){
            Processes[id]->blocked = nullptr;
            out << "ProcessName: "<< Processes[id]->getName() << " ClockValue: " << Processes[id]->time << " MsgReceived "<< cmd->message << " FromProcess: " << cmd->name << "\n";
        }
        else {
            Processes[id]->blocked = Processes[getProcessNumber(cmd->name)];
            Processes[id]->blockingMsg.payload = cmd->message;
            Processes[id]->blockingMsg.fromId = cmd->name;
            Processes[id]->decreaseCmd();
        }
    }
    else if(cmdi->whatType() == 2){
        SendCommand<T>* cmd = (SendCommand<T>*)(cmdi);
        Processes[id]->time.increment();
        out << "ProcessName: " << Processes[id]->getName() << " ClockValue: " << Processes[id]->time << " MsgSent: " << cmd->message << " ToTheProcess: ";
        out << "{";
        for(auto i:cmd->ids){
            out << i << ",";
        }
        out << "}\n";
        for(auto i:cmd->ids){
            if(getProcessNumber(i)==-1)continue;
            addMessageToProcessQueue(getProcessNumber(i), new Message(cmd->message,Processes[id]->time,Processes[id]->getName()));
            if(getProcessNumber(i)!=-1 && Processes[getProcessNumber(i)]->blocked != nullptr){
                if(Processes[getProcessNumber(i)]->checkMsgQueue(Processes[getProcessNumber(i)]->blockingMsg)){
                    Processes[getProcessNumber(i)]->blocked = nullptr;
                    out << "ProcessName: "<< Processes[getProcessNumber(i)]->getName() << " ClockValue: " << Processes[getProcessNumber(i)]->time << " MsgReceived "<< cmd->message << " FromProcess: " << Processes[id]->getName() << "\n";
                    Processes[getProcessNumber(i)]->increaseCmd();
                    if(Processes[getProcessNumber(i)]->completed()){
                        int pid = getProcessNumber(i);
                        idToProcessNumber.erase(Processes[pid]->getName());
                        Processes.erase(Processes.begin()+pid);
                        for(int i = 0;i<(int)Processes.size();i++){idToProcessNumber[Processes[i]->getName()] = i;};
                    }
                }
            }
        }
    }
    else {
        throw std::runtime_error("Not a command Type\n");
    }
    Processes[id]->increaseCmd();
    return true;
}

template class ProcessManager<std::string>;