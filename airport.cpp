/*
airport.cpp

*/
// Airport.cpp

#include "airport.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Airport::Airport(string airport_name): Objects_clock(0, 0, 0) 
{
    this->Airport_name = airport_name;

    // Initialize Airport_ID to a default value 
    Airport_ID = 0;

    // Set the initial value of Airport_open 
    Airport_open = true;
}

//Add reference to TimeManager object, then complete object creation
void Airport::setTimeManager(TimeManager *time_manager){

    //Assign our time_manager
    this->time_manager = time_manager;

    /* Continue with object creation
    for(int i = 0; i < 5; i++) 
    {
        Passenger* passenger_group = new Passenger(i);
        //Register passenger group
        registerPassengerGroup(passenger_group);

        //Creating and registering start gates
        Gate* start_gate = new Gate(i);
        registerGate(start_gate);

        //Creating and registering target gates
        Gate* target_gate = new Gate(i);
        registerGate(target_gate);
        
    }*/
}
//Register a passenger_group (to vector) and as an observer
void Airport::registerPassengerGroup(Passenger* passenger_group)
{
    //Note: Passenger no longer time Observer
    //Only add to vector
    All_passenger_groups.push_back(passenger_group);
}

//Register a gate (to vector) and as an observer
void Airport::registerGate(Gate* gate)
{
    time_manager->addObserver(gate);
    All_gates.push_back(gate);
}

//When time gets updated
void Airport::onTimeUpdate(Clock& new_time) 
{

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    Objects_clock = new_time;
    cout << "Airport " << Airport_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    

    //Say that we are done
    TimeObserver::setIsDone();
}

//Getters

// Return Airport ID
int Airport::getAirportID() 
{
    return Airport_ID;
}

// Return Airport name
string Airport::getAirportName() 
{
    return Airport_name;
}

// Return whether or not open
bool Airport::getAirportOpen() 
{
    return Airport_open;
} 

//Setters

// Set Airport ID
void Airport::setAirportID(int id) 
{
    Airport_ID = id;
}

// Set Airport name
void Airport::setAirportName(string name) 
{
    Airport_name = name;
}

//Multi-action

// Finds gate based on Gate_ID, returns the position in vector so if i search for a specific gate id it will return position of vector
int Airport::findGate(int GateID) 
{
    // Iterate through all gates in the vector
    for (size_t i = 0; i < gates.size(); ++i) 
    {
        // Check if the Gate_ID of the current gate matches the provided GateID
        if (All_gates[i]->getGateID() == GateID) 
        {
            // Return the position (index) in the vector where the gate with the matching ID is found
            return static_cast<int>(i);
        }
    }
    // If no gate with the given ID is found, return -1 to indicate that the gate is not found
    return -1;
}

//Assigns each passenger group to a start and target gate
void Airport::movePassengers()
{
    for(Gate& gate : gates)
    {
        for(passengerMovement& movement : gate.getPassengerMovements())
        {
            movement.remainingTime -= 10;
            if(movement.remainingTime <= 0)
            {
                gates[movement.targetGateID].createPassengers(movement.groupID);
                gate.removePassengerMovement(movement.groupID);
            }
        }
    }

}

//Will decrement a clock so that once clock is at 0 it will signify a passenger's arrival at target gate
void Airport::moveToGate()
{

}