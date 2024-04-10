/*
airport.cpp

*/
// Airport.cpp

#include "airport.h"
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

// Constructor
Airport::Airport(int airport_ID, string airport_name, double longitude, double latitude): Objects_clock(0, 0, 0)
{


    this->Airport_name = airport_name;
    this->longitude = longitude;
    this->latitude = latitude;

    // Initialize Airport_ID to a default value 
    Airport_ID = airport_ID;

    // Set the initial value of Airport_open 
    Airport_open = true;

    //Continue with object creation
    for(int i = 0; i < 5; i++) 
    {
        //Register passenger group
        //registerPassengerGroup(passengerGroupID);
        //Creating and registering gates
        Gate* gateID = new Gate(i);
        registerGate(gateID);
        
        for(int x=0; x <5; x++){
           Passenger* passengerGroupID = new Passenger(x); 
           //All_gates[gateID]->Departing_passengers.push_back(passengerGroupID);
        }     
    }

    
}

//Add reference to TimeManager object, then complete object creation
void Airport::setTimeManager(TimeManager *time_manager){

    //Assign our time_manager
    this->time_manager = time_manager;

}

void Airport::updateDay(int Day){
    this->day = Day;
}

void Airport::setLogObject(Logger *log_pointer){

    //Assign our logger object
    this->Log_object = log_pointer;
    
}
//Register a passenger_group (to vector) and as an observer
void Airport::registerPassengerGroup(Passenger* passengerGroupID)
{
    //Only add to vector
    All_passenger_groups.push_back(passengerGroupID);

}
//Register a gate (to vector) and as an observer
void Airport::registerGate(Gate* gateID)
{
    //time_manager->addObserver(gateID);
    All_gates.push_back(gateID);
}

//When time gets updated
void Airport::onTimeUpdate(Clock& new_time) 
{

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    //Report time update to cout
    Objects_clock = new_time;

    if(debugging){
    cout << "Airport " << Airport_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
    }

   

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

//Will move passenger groups to the target gate ID 

void Airport::transferToGate(int gate_ID, vector<Passenger> All_passenger_groups){

    //Assign passed vector as the vaector at gate
    All_gates[gate_ID]->Arriving_passengers = All_passenger_groups;
    //for(int x = 0; x < All_passenger_groups.size(); x++)
    //{
        //cout << "Passenger groups: " << All_passenger_groups[x] << endl
    //}
     cout << "Size of Arriving_passengers vector: " << All_gates[gate_ID]->Arriving_passengers.size();
}

vector<Passenger> Airport::transferToPlane(int gate_ID){

    //Placeholder vector
    vector<Passenger> temp;

    //Set departing passengers vector
    All_gates[gate_ID]->Departing_passengers = All_gates[gate_ID]->Arriving_passengers;

    //Assign vector to placeholder
    temp = All_gates[gate_ID]->Departing_passengers;
    cout << "Size" << temp.size();
    //Clear vector at gate
    All_gates[gate_ID]->Departing_passengers.clear();
    
    //Return the original vector at gate
    return temp;


}
void Airport::freeGate(int gate_ID){
    //Set given gate to free
    All_gates[gate_ID]->setInUse(false);

    //Tell logger its been freed
    Log_object->logAirportUpdate(this->Airport_ID, 3, gate_ID, this->Objects_clock);
}
