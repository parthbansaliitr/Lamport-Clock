// #include "Process.h"
// #include "ProcessManager.h"
// template<typename T>
// bool Process<T>::execute(void* managers){
//     ProcessManager<T>* manager = (ProcessManager<T>*)(managers);
//     if(blocked != nullptr)return false;
//     if(Commands[cmdsExecuted]->whatType() == 0){
//         PrintCommand* cmd = (PrintCommand*)(Commands[cmdsExecuted]);
//     }
//     else if(Commands[cmdsExecuted]->whatType() == 1){
//         RecvCommand<T>* cmd = (RecvCommand<T>*)(Commands[cmdsExecuted]);
//         blocked = manager->getProcessFromName(cmd->name);
//     }
//     else if(Commands[cmdsExecuted]->whatType() == 1){
//         SendCommand<T>* cmd = (SendCommand<T>*)(Commands[cmdsExecuted]);
//         for(auto i:cmd->ids){
//             manager->addMessageToProcessQueue();
//         }
//     }
//     else {
//         throw std::runtime_error("Not a command Type\n");
//     }
// }