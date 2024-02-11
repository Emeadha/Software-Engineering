/*
airline.h

Airline object header file
*/

// airport.h
#ifndef AIRLINE_H
#define AIRLINE_H


#include "timeObserver.h"
#include "clock.h"
#include "timeManager.h"
#include "plane.h"
#include "airport.h"
#include <string>
#include <iostream>

using namespace std;   

class Airline : public TimeObserver {
public:

    //Public variables
    //Time manager object
    TimeManager* time_manager;
    //Airlines name
    string Airline_name;
    //Our clock object
    Clock Objects_clock;

    //Vector for planes and airports
    //These are the planes the airline owns, and places it can go
    vector<Plane*> All_planes;
    vector<Airport*> All_airports;

    Airline(TimeManager *time_manager, string airport_name);

    //Destructor
    ~Airline();

    // Register a plane as an observer
    void registerPlane(Plane* plane);

    // Register an airport as an observer
    void registerAirport(Airport* airport);


    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    
};

#endif // AIRLINE_H
