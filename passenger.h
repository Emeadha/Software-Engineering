/*
    passenger.h

    Passenger object header file
*/
// passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H
#include "TimeObserver.h"
#include <string>

class Passenger : public TimeObserver {
public:
    std::string name;
    Clock current_time;

    Passenger(const std::string& passenger_name);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(const Clock& new_time) override;
};

#endif // PASSENGER_H
