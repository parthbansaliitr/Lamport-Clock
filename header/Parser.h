#pragma once
#include<iostream>
#include <istream>
#include <fstream>
#include "ProcessManager.h"
class Parser{
private:
    std::ifstream& in;
    std::ofstream& out;
    ProcessManager<std::string>* manager;
public:
    Parser(std::ifstream& input, std::ofstream &output, ProcessManager<std::string>* manager) 
    : in(input) , out(output), manager(manager){

    }
    bool startParser();
};