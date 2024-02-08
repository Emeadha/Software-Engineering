/*
timeObserver.h

Plane object header file
*/
// TimeObserver.h
#ifndef TIME_OBSERVER_H
#define TIME_OBSERVER_H
#include "Clock.h"

using namespace std;

class TimeObserver {
public:
    virtual void onTimeUpdate(Clock& new_time) = 0;

    //Return whether observer got all the way through the update
    bool getIsDone() {
        return Is_done;
    }

    //Set update sucsess
    void setIsDone() {
        Is_done = true;
    }

    //Set update failure or not ready
    void setIsNotDone() {
        Is_done = false;
    }

    //Set whether observer succeeded update
    bool Is_done = false;
};

#endif // TIME_OBSERVER_H