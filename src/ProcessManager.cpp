#include "ProcessManager.h"

template<typename T>
bool ProcessManager<T>::validateProcesses(){
    for(Process<T>* p:Processes){
        int sz = p->getCmdSz();
        for(int i = 0;i<sz;i++){
            Command* cmd = p->getCmd();
            if(cmd == nullptr)return false;
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
            throw std::runtime_error("Deadlocked Found");
        }
        exec%=Processes.size();
        Processes[exec]->execute();
        if(Processes[exec]->completed()){
            Processes.erase(exec);
            exec--;
        }
        exec++;
    }
}
template<typename T>
bool ProcessManager<T>::isDeadlocked(){
    for(int i = 0;i<Processes.size();i++){
        if(Processes[i]->blocked == nullptr){
            return false;
        }
    }
    return true;
}
template<typename T>
void ProcessManager<T>::PrintDeadlock(){
    out << "These processes are in deadlocked:\n";
    for(Process<T>* p: Processes){
        out << p->getName() << " waiting for ";
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
    }
    else if(cmdi->whatType() == 1){
        RecvCommand<T>* cmd = (RecvCommand<T>*)(cmdi);
        getProcessFromName(cmd->name);
    }
    else if(cmdi->whatType() == 1){
        SendCommand<T>* cmd = (SendCommand<T>*)(cmdi);
        for(auto i:cmd->ids){
            addMessageToProcessQueue();
        }
    }
    else {
        throw std::runtime_error("Not a command Type\n");
    }
    Processes[id]->increaseCmd();
}
// template class ProcessManager<std::string>;
