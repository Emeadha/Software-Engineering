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
#include "gate.h"
#include "Passenger.h"

#include <string>
#include <iostream>
#include <vector>

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

    //Constructor
    Airport(TimeManager *time_manager, string airport_name);

    // Register a passenger_group (to vector) and as an observer
    void registerPassengerGroup(Passenger* passenger_group);

    // Register a gate (to vector) and as an observer
    void registerGate(Gate* gate);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    // Getters
    int getAirportID() const; // Return Airport ID
    const std::string& getAirportName() const; // Return Airport name
    bool getAirportOpen() const; // Return whether or not open

    // Setters
    void setAirportID(int id); // Set Airport ID
    void setAirportName(const std::string& name); // Set Airport name

    // Multi-action
    int findGate(int GateID) const; // Finds gate based on Gate_ID, returns the position in vector
};


#endif // AIRPORT_H
