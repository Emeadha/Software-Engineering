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
#include "logger.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <mutex>

    //Mutex
    //extern mutex Airport_Con_Mutex;

using namespace std;   

class Airport : public TimeObserver {
private:
    //Variables
    int Airport_ID = -1; // Primary key for airport
    Clock Objects_clock; // Instance of the clock object for the airport, used to keep simulation synchronization
    //Clock Passenger_clock;
    string Airport_name; // Airport name

    //Pointers to nessesary objects
    TimeManager* time_manager = nullptr;
    Logger* Log_object = nullptr; 

    bool Airport_open; // Whether or not airport is open
    bool atGate = true; //Whether or not the passenger group is at their gate

    bool debugging = false;

public:

    //Vector for all passenger and gate objects
    vector<Passenger*> All_passenger_groups;
    vector<Passenger*> passengersAtGate; //vector of copied passenger groups that have atGate == true
    vector<Passenger*> atGateGroups; //temp vector
    vector<Gate*> All_gates;
    //Constructor
    Airport(int airport_ID, string airport_name);

    // Register a passenger_group (to vector) and as an observer
    void registerPassengerGroup(Passenger* passengerGroupID);

    // Register a gate (to vector) and as an observer
    void registerGate(Gate* gateID);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    // Getters
    int getAirportID(); // Return Airport ID
    string getAirportName(); // Return Airport name
    bool getAirportOpen(); // Return whether or not open

    // Setters
    void setTimeManager(TimeManager *time_manager); //CRITICAL STEP - passes a a refernce to time manager
    void setLogObject(Logger *log_pointer); //CRITICAL STEP - passes a reference to logger object
    void setAirportID(int id); // Set Airport ID
    void setAirportName(string name); // Set Airport name

    // Multi-action
    int findGate(int GateID); // Finds gate based on Gate_ID, returns the position in vector

    //will "move" passenger grous to assigned gate
    void passengerMovement();

};


#endif // AIRPORT_H
