#pragma once
#include <algorithm>
#include <fstream>
template<typename T>
class Clock{
private:
    T time;
public:
    Clock(){
        time = 0;
    }
    Clock(T time){
        this->time = time;
    }
    void increment(){
        time++;
    }
    void decrement(){
        time--;
    }
    void updateClock(Clock<T> receivedClock){
        time = std::max(receivedClock.time, time);
        time++;
    }
    friend std::ostream& operator<<(std::ostream &out, const Clock<T>& c){
        out << c.time;
        return out;
    }
};
template class Clock<int>;