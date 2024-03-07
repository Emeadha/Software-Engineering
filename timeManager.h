/*
timeManager.h

Time manager header

timeManager - Controls the time of the simulation, pushes changes in the time 
to other objects. Hold a vector of all observers, or objects that will be
affected by the time update. This will be the only object that actually
“progresses time”, so to speak to avoid inconsistencies.

Who makes this object? Main

What’s its goal? Hold a vector of all observers, and send out updates of the new time.

*/
// timeManager.h
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include "timeObserver.h"
#include "clock.h"
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

class TimeManager {
private:
    Clock simulation_time;
    vector<TimeObserver*> observers;

public:
    // Constructor
    TimeManager();

    void startSimulation();
    void updateSimulationTime(int hours, int minutes, int seconds);
    void addObserver(TimeObserver* observer);
    void notifyObservers();
};

#endif // TIME_MANAGER_H
