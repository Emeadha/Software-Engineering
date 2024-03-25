/*
airline.h

Airline object header file

Airline - Airline is the overarching object with all the sum knowledge of the
simulation. It will create and store airport, plane and flight vectors. It
will be in charge of scheduling flights via the information read in from the
timetable, and making dynamic decisions such as rescheduling.

Who makes this object? Main

Is it a time observer? Yes

What’s its goal? Manage the whole simulation
testing testing
*/

// airport.h
#ifndef AIRLINE_H
#define AIRLINE_H


#include "timeObserver.h"
#include "clock.h"
#include "timeManager.h"
#include "flight.h"
#include "plane.h"
#include "airport.h"
#include "input.h"
#include "logger.h"

#include <string>
#include <fstream>
#include <iostream>
#include <mutex>


using namespace std;   

class Airline : public TimeObserver {

private:
    //Airlines name
    string Airline_name;

    //Output file name
     ofstream flightLog;

    //Vector for planes and airports
    //These are the planes the airline owns, and places it can go
    vector<Flight*> All_flights;
    vector<Plane*> All_planes;
    vector<Airport*> All_airports;

    bool scheduleNeeded = false;

    bool debugging = false;


public:

    //Public variables
    //Time manager object
    TimeManager* time_manager;

    //Logger object
    Logger* Log_object;

    //Input object
    Input Input_object;

    //Our clock object
    Clock Objects_clock;


    // --------------
    // Constructor/Destructor
    // --------------

    Airline(TimeManager *time_manager, string airport_name, Input Input_object, Logger *Log_object);

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

    void scheduleFlights(); // Schedule all unscheduled flights

    void loadFlights();//Loads flights from vector (passed by input object), then fill out rest of missing info

    // Eventually want cancel flight method

    // ---------------
    // "Searching" methods
    // ---------------
    //Search plane ID, returns position in array
    int findPlaneID(string plane_name);
    int findAirportID(string airport_name);

      // ---------------
    // "Passenger transfer" methods
    // ---------------
    void transferToGate(int airport_ID, int plane_ID); //Takes vector from plane and puts to arrival vector in gate
    void transferToPlane(int airport_ID, int plane_ID); //Takes departure vector from gate and puts in plane
    void negotiateGate(int airport_ID, int plane_ID); //Assigns plane a new availible target gate
    void freeGate(int airport_ID, int plane_ID); //Free up gate after passengers unboarded



    
};

#endif // AIRLINE_H
