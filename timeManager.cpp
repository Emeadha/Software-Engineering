/*
timeManager.cpp

Time manager implementation file
*/
// TimeManager.cpp
#include "TimeManager.h"

TimeManager::TimeManager() : simulation_time(0, 0, 0) {}

void TimeManager::updateSimulationTime(int hours, int minutes, int seconds) {
    simulation_time = Clock(hours, minutes, seconds);
    notifyObservers();
}

void TimeManager::addObserver(TimeObserver* observer) {
    observers.push_back(observer);
}

void TimeManager::notifyObservers() {
    for (auto observer : observers) {
        observer->onTimeUpdate(simulation_time);
    }
}