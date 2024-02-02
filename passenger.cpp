/*
passenger.cpp

Passenger object implementation file
*/
// Passenger.cpp
#include "Passenger.h"
#include <iostream>

Passenger::Passenger(string passenger_name) : name(passenger_name), current_time(0, 0, 0) {}

void Passenger::onTimeUpdate(Clock& new_time) {
    current_time = new_time;
    cout << "Passenger " << name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
}