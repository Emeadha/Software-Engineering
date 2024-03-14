/*
    passenger.h

    Passenger object header file

    Passenger_group - Passenger group represents a group of passengers (right
    now 10 people), who have the same origin and destination. When they get
    a flight, the corresponding ticket cost is recorded as revenue for the
    airline. Additionally, the number of passenger groups transported also
    needs to be communicated to the end report. Passenger group doesn’t do much
    by itself, but is instead passed between gates and planes until they reach
    their final destination, in which case the object will be destroyed.

    Who makes this object? Airport

    Is it a time observer? Yes

    What’s its goal? Be transported through gates and planes to the final destination.

*/
// passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H
#include "timeObserver.h"
#include <string>

using namespace std;

class Passenger {
public:
    int Passenger_group_ID;
    Clock Objects_clock;

    Passenger(int Passenger_group_ID);

    // Implement the TimeObserver interface
    // virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // PASSENGER_H
