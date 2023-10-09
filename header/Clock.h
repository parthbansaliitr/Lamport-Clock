#pragma once
#include <algorithm>
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
        time = max(receivedClock.time, time);
        time++;
    }
};