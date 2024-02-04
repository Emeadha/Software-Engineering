/*
airport.cpp

*/
// Airport.cpp
#include "Airport.h"
#include <iostream> 
#include "clock.h"


Airport::Airport(string airport_name) : name(airport_name), Objects_clock(0, 0, 0) {}

void Airport::onTimeUpdate(Clock& new_time) {
    Objects_clock = new_time;
    cout << "Airport " << name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
}