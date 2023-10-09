#include "./header/Parser.h"
#include "./header/ProcessManager.h"
#include <iostream>
#include <fstream>
int main(){
    std::ifstream in("./input.txt");
    std::ofstream out("./output.txt"); 
    ProcessManager<std::string>* P = new ProcessManager<std::string>(out);
    Parser* parser = new Parser(in, out, P);
    parser->startParser();
    // P->addProcess("afdsf");
    std::cout << "Successfull\n";
}