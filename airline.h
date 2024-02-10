/*
airline.h

Airline object header file
*/

// airport.h
#ifndef AIRLINE_H
#define AIRLINE_H


#include "TimeObserver.h"
#include "Clock.h"
#include "TimeManager.h"
#include "flight.h"
#include "Plane.h"
#include "Airport.h"
#include <string>
#include <iostream>

using namespace std;   

class Airline : public TimeObserver {

private:
    //Airlines name
    string Airline_name;

    //Vector for planes and airports
    //These are the planes the airline owns, and places it can go
    vector<Flight> All_flights;
    vector<Plane*> All_planes;
    vector<Airport*> All_airports;

    bool scheduleNeeded = false;


public:

    //Public variables
    //Time manager object
    TimeManager* time_manager;

    //Our clock object
    Clock Objects_clock;

    // --------------
    // Constructor/Destructor
    // --------------

    Airline(TimeManager *time_manager, string airport_name);

    //Destructor
    ~Airline();

    // --------------
    // Creation/Registration methods
    // --------------

    // Register a plane as an observer
    void registerPlane(Plane* plane);

    // Register an airport as an observer
    void registerAirport(Airport* airport);


    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    // --------------
    // "Scheduler" methods
    // --------------

    // Schedule a flight
    void scheduleFlight();

    // Add a flight to vector (this is what should be calle dwhen reading
    // timetable)
    void addFlightToVector();

    // Eventually want cancel flight method




    
};

#endif // AIRLINE_H
