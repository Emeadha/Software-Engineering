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

    //Continue with object creation
    for(int i = 0; i < 5; i++) 
    {
        Passenger* passengerGroupID = new Passenger(i);
        //Register passenger group
        registerPassengerGroup(passengerGroupID);

        //Creating and registering gates
        Gate* gateID = new Gate(i);
        registerGate(gateID);
        
    }
}

//Add reference to TimeManager object, then complete object creation
void Airport::setTimeManager(TimeManager *time_manager){

    //Assign our time_manager
    this->time_manager = time_manager;

}

//Register a passenger_group (to vector) and as an observer
void Airport::registerPassengerGroup(Passenger* passengerGroupID)
{
    //Note: Passenger no longer time Observer
    //Only add to vector
    All_passenger_groups.push_back(passengerGroupID);
}

//Register a gate (to vector) and as an observer
void Airport::registerGate(Gate* gateID)
{
    time_manager->addObserver(gateID);
    All_gates.push_back(gateID);
}

//When time gets updated
void Airport::onTimeUpdate(Clock& new_time) 
{

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    //Report time update to cout
    Objects_clock = new_time;
    cout << "Airport " << Airport_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Call passengerMovements to see who is at gate
    passengerMovement();     

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
    for (size_t i = 0; i < All_gates.size(); ++i) 
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

//Will decrement a clock so that once clock is at 0 it will signify a passenger's arrival at target gate
void Airport::passengerMovement()
{
    for(int i = 0; i < All_passenger_groups.size(); i++)
    {
        if(atGate != true)
        {
            //decrement delay clock by 10 min 
        }
        else
        {
            for(int x = 0; x < sizeof(All_gates); x++)
                for(int j = 0; j < sizeof(All_passenger_groups); j++)
                {
                    
                }

        }

    }
}
