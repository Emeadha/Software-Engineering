/*
airport.h

Airport object header file
*/

// airport.h
#ifndef AIRPORT_H
#define AIRPORT_H


#include "TimeObserver.h"
#include "Clock.h"
#include "timeManager.h"
#include "Passenger.h"

#include <string>
#include <iostream>


using namespace std;   

class Airport : public TimeObserver {
public:
    //Variables
    string Airport_name;
    Clock Objects_clock;
    TimeManager* time_manager;

    //Vector for passenger objects
    vector<Passenger*> All_passenger_groups;

    //Constructor
    Airport(TimeManager *time_manager, string airport_name);

    // Register a passenger_group (to vector) and as an observer
    void registerPassengerGroup(Passenger* passenger_group);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // AIRPORT_H
