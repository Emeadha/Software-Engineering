/*
airport.h

Airport object header file

Airport - Airport represents a singular airport location which the client has 
access to. Airport will create both gate and passenger group objects, and
store them in vectors. Airport will receive information regarding flights via
the Airline, and will hold important data about itself such as geographical
location.

Who makes this object? Airline

Is it a time observer? Yes

What’s its goal? To hold passenger groups and gates

*/

// airport.h
#ifndef AIRPORT_H
#define AIRPORT_H


#include "timeObserver.h"
#include "clock.h"
#include "timeManager.h"
#include "gate.h"
#include "passenger.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>


using namespace std;   

class Airport : public TimeObserver {
public:
    //Variables
    int Airport_ID; // Primary key for airport
    Clock Objects_clock; // Instance of the clock object for the airport, used to keep simulation synchronization
    string Airport_name; // Airport name
    TimeManager* time_manager;
    bool Airport_open; // Whether or not airport is open

    //Vector for all passenger and gate objects
    vector<Passenger*> All_passenger_groups;
    vector<Gate*> All_gates;
    vector<Gate> gates;

    //Constructor
    Airport(string airport_name);

    // Register a passenger_group (to vector) and as an observer
    void registerPassengerGroup(Passenger* passenger_group);

    // Register a gate (to vector) and as an observer
    void registerGate(Gate* gate);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    // Getters
    int getAirportID(); // Return Airport ID
    string getAirportName(); // Return Airport name
    bool getAirportOpen(); // Return whether or not open

    // Setters
    void setTimeManager(TimeManager *time_manager); //CRITICAL STEP - passes a a refernce to time manager
    void setAirportID(int id); // Set Airport ID
    void setAirportName(string name); // Set Airport name

    // Multi-action
    int findGate(int GateID); // Finds gate based on Gate_ID, returns the position in vector

    //will decrement delay object
    void movePassengers();

    //will "move" passenger grous to assigned gate
    void moveToGate();

};


#endif // AIRPORT_H
