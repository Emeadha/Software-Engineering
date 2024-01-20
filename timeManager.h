/*
timeManager.h

Time manager header
*/
// timeManager.h
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include "TimeObserver.h"
#include <vector>

class TimeManager {
private:
    Clock simulation_time;
    std::vector<TimeObserver*> observers;

public:
    void updateSimulationTime(int hours, int minutes, int seconds);
    void addObserver(TimeObserver* observer);
    void notifyObservers();
};

#endif // TIME_MANAGER_H