/*
timeManager.h

Time manager header
*/
// timeManager.h
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include "TimeObserver.h"
#include "Clock.h"
#include <vector>

using namespace std;

class TimeManager {
private:
    Clock simulation_time;
    vector<TimeObserver*> observers;

public:
    // Constructor
    TimeManager();

    void updateSimulationTime(int hours, int minutes, int seconds);
    void addObserver(TimeObserver* observer);
    void notifyObservers();
};

#endif // TIME_MANAGER_H