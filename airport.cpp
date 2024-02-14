/*
airport.cpp

*/
// Airport.cpp

#include "airport.h"

using namespace std;

// Constructor
Airport::Airport(TimeManager *time_manager, string airport_name)
    : time_manager(time_manager), Objects_clock(0, 0, 0) 
{
    this->Airport_name = airport_name;

    // Initialize Airport_ID to a default value 
    Airport_ID = 0;

    // Set the initial value of Airport_open 
    Airport_open = true;

    // Create passenger objects
    for(int i = 0; i < 5; i++) 
    {
        Passenger* passenger_group = new Passenger(i);
        //Register passenger group
        registerPassengerGroup(passenger_group);
    }

    // Create gate objects
    for(int i = 0; i < 5; i++) 
    {
        Gate* gate = new Gate(i);
        //Register gate
        registerGate(gate);
    }

}

//Register a passenger_group (to vector) and as an observer
void Airport::registerPassengerGroup(Passenger* passenger_group)
{
    time_manager->addObserver(passenger_group);
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