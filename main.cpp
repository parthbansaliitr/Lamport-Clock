#include "./header/Parser.h"
#include "./header/ProcessManager.h"
#include <iostream>
int main(){
    ProcessManager<std::string>* P = new ProcessManager<std::string>();
    P->addProcess("afdsf");
    std::cout << "Successfull\n";
}