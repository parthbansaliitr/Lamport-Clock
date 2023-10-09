#include "../header/ProcessManager.h"

template<typename T>
bool ProcessManager<T>::validateProcesses(){
    for(Process<T>* p:Processes){
        int sz = p->getCmdSz();
        for(int i = 0;i<sz;i++){
            Command* cmd = p->getCmd();

        }
    }
    return true;
}
// template class ProcessManager<std::string>;
