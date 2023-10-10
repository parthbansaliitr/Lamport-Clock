#include "./header/Parser.h"
#include "./header/ProcessManager.h"
#include <iostream>
#include <fstream>
int main(){
    std::ifstream in("./input.txt");
    std::ofstream out("./output.txt"); 
    ProcessManager<std::string>* P = new ProcessManager<std::string>(out);
    Parser* parser = new Parser(in, out, P);
    if(!parser->startParser()){
        out << "Wrong Input Format\n";
    }
    else{
        out << "Parsing Completes\n";
        if(!P->validate()){
            out << "Validation of Input Unsuccessfull contain recv/send from/to unknown process\n";
        }
        else{
            if(!P->execute()){
                out << "Execution Failed Contain DeadLock Or Some Message Received Which is Never Sent\n";
            }
        }
    }
    // P->addProcess("afdsf");
    
}