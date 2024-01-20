/*
airport.cpp

*/
// Airport.cpp
#include "Airport.h"
#include <iostream> 
#include "clock.h"

Airport::Airport(const std::string& airport_name) : name(airport_name), current_time(0, 0, 0) {}

void Airport::onTimeUpdate(const Clock& new_time) {
    current_time = new_time;
    std::cout << "Airport " << name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << std::endl;
}