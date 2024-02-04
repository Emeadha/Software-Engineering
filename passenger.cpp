/*
passenger.cpp

Passenger object implementation file
*/
// Passenger.cpp
#include "Passenger.h"
#include <iostream>

Passenger::Passenger(string passenger_name) : name(passenger_name), Objects_clock(0, 0, 0) {}

void Passenger::onTimeUpdate(Clock& new_time) {
    Objects_clock = new_time;
    cout << "Passenger " << name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
}