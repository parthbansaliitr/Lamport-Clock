#include "../header/Parser.h"
#include <vector>
#include <sstream>
#include "../header/Process.h"
bool Parser::startParser(){
    out << "Started Parsing\n";
    std::string s;
    bool started = false;
    Process<std::string>* CurrentProcess;
    while(std::getline(in, s)){
        std::vector<std::string>splitStr;
        std::stringstream inputStr(s);
        std::string temp;
        while(std::getline(inputStr, temp, ' ')){
            splitStr.push_back(std::move(temp));
        }
        int splitStrSz = splitStr.size();
        if(splitStrSz == 3 && splitStr[0] == "begin" && splitStr[1] == "process"){
            if(started){
                throw std::runtime_error("Invalid Input One process is already started trying to start another process");
            }
            started = true;
            manager->addProcess(splitStr[2]);
            CurrentProcess = manager->getLastProcess();
        }
        else if(splitStrSz == 2 && splitStr[0] == "print"){
            if(!started){
                throw std::runtime_error("No Process Started");
            }
            PrintCommand* newCommand = new PrintCommand(splitStr[1]);
            CurrentProcess->addCommand(newCommand);
        }
        else if(splitStrSz == 3 && splitStr[0] == "recv"){
            if(!started){
                throw std::runtime_error("No Process Started");
            }
            auto newCommand = new RecvCommand(splitStr[1], splitStr[2]);
            CurrentProcess->addCommand(newCommand);
        }   
        else if(splitStrSz == 3 && splitStr[0] == "send"){
            if(!started){
                throw std::runtime_error("No Process Started");
            }
            std::vector<std::string>ids;
            if(splitStr[1][0] != '(' || splitStr[1][splitStr[1].size()-1] != ')'){
                throw std::runtime_error("Wrong Format of ids of Processes");
            }
            std::string cur = "";
            for(int i = 1;i<splitStr[1].size()-1;i++){
                if(splitStr[1][i] == ','){
                    ids.push_back(std::move(cur));
                }
                else{
                    cur+=splitStr[1][i];
                }
            }
            ids.push_back(std::move(cur));
            auto newCommand = new SendCommand(ids, splitStr[2]);
            CurrentProcess->addCommand(newCommand);
        }
        else if(splitStrSz == 2 && splitStr[0] == "end" && splitStr[1] == "process"){
            if(!started){
                throw std::runtime_error("No Process Started");
            }
            started = false;
        }
        else{
            throw std::runtime_error("Wrong Input");
        }
    }
    return true;
}