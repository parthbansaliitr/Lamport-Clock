#pragma once
// template <typename T>
class Command{
// private:
public:
    int type;
    // void execute(){
    //     ((T*)this)->executeCmd();
    // }
    virtual void execute(){

    }
    virtual bool validate(){
        return false;
    }
    int whatType(){return type;}
};