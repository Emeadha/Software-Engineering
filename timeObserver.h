/*
timeObserver.h

Plane object header file
*/
// TimeObserver.h
#ifndef TIME_OBSERVER_H
#define TIME_OBSERVER_H
#include "Clock.h"

class TimeObserver {
public:
    virtual void onTimeUpdate(const Clock& new_time) = 0;
};

#endif // TIME_OBSERVER_H