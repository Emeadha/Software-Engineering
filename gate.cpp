/*
gate.cpp

Gate object implementation file
*/
// gate.cpp
#include "gate.h"
#include <iostream>

Gate::Gate(int Gate_ID) :  Objects_clock(0, 0, 0) {
    this->Gate_ID = Gate_ID;
}

void Gate::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    Objects_clock = new_time;
    cout << "Gate " << Gate_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Say that we are done
    TimeObserver::setIsDone();
}