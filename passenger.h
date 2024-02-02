/*
    passenger.h

    Passenger object header file
*/
// passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H
#include "TimeObserver.h"
#include <string>

using namespace std;

class Passenger : public TimeObserver {
public:
    string name;
    Clock current_time;

    Passenger(string passenger_name);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // PASSENGER_H
