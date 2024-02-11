/*
    passenger.h

    Passenger object header file
*/
// passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H
#include "timeObserver.h"
#include <string>

using namespace std;

class Passenger : public TimeObserver {
public:
    int Passenger_group_ID;
    Clock Objects_clock;

    Passenger(int Passenger_group_ID);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // PASSENGER_H
