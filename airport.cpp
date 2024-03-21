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
Airport::Airport(int airport_ID, string airport_name): Objects_clock(0, 0, 0)
{
    //Mutex lock for saftey
    //lock_guard<mutex> lock(Airport_Con_Mutex);


    this->Airport_name = airport_name;

    // Initialize Airport_ID to a default value 
    Airport_ID = airport_ID;

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

//Will move passenger groups to the target gate ID 
void Airport::passengerMovement()
{   
    //cout << "Passenger Clock: " << Passenger_clock.hours <<":" << Passenger_clock.minutes << endl;
    //int totalMinutes = Passenger_clock.hours * 60 + Passenger_clock.minutes;
    //cout << "total Minutes " << totalMinutes << endl;
    int delay;
    int gateNumber = 0;
    int targetGateNumber=1; 
    

    for(int w = 0; w < All_passenger_groups.size(); w++)
    {
        All_passenger_groups[w]->assignedGate = gateNumber;
        gateNumber++;
        cout << All_passenger_groups[w] << "is assigned to gate " << gateNumber << endl;    

    }
    for( int x=0; x < All_passenger_groups.size(); x++){
                All_passenger_groups[x]->assignedTargetGate = targetGateNumber;
                targetGateNumber++;
                cout << All_passenger_groups[x] << "is assigned to target gate " << targetGateNumber << endl;
            }
    
    for(int i = 0; i < All_passenger_groups.size(); i++)
    {
      //delay = Objects_clock.minutes - Passenger_clock.minutes;
      //cout << "delayed by " << delay << endl; 
      //cout << Passenger_clock.hours << ":" << Passenger_clock.hours << endl;
        
        //if(All_passenger_groups[i]->assignedGate == targetGateNumber)
        //{
          //  atGate = false;
          //  cout << "in if statement" << endl;
       // }
        //if passengers are not at gate, clock will decremement by 10 minutes
        //once clock == 0, the passenger group atGate bool will be flipped to true and copied to temp vector 
        if(All_passenger_groups[i]->atGate == false)
        {
            //Passenger->decrementPassengerDelay(durationOfUpdate);
            //cout << "Debugging: " << delay << "minutes" << endl;
            //delay = Objects_clock.minutes - Passenger_clock.minutes;
            
            cout << "-----------------------in next if statement-------------------" << endl;
            if(delay >= 0)
            {
                All_passenger_groups[i]->atGate = true;
                cout << All_passenger_groups[i] << "is at gate" << endl;
                atGateGroups.push_back(All_passenger_groups[i]);
            }
        }
        
        //if passengers are already at gate they are moved to temp vector
        else{
    
            atGateGroups.push_back(All_passenger_groups[i]);
            cout << "passenger group " << " already at gate -> moved to temp vector" << endl;
        }

            

    }
    
    //passenger groups are removed for the all passenger group vector
    //then are moved from temp vector to final vector passengersAtGate
    /*auto removeIter = std::remove_if(All_passenger_groups.begin(),All_passenger_groups.end(), [](Passenger* passenger) { 
        return passenger->atGate; 
     });

    All_passenger_groups.erase(removeIter, All_passenger_groups.end());

    passengersAtGate.insert(passengersAtGate.end(), atGateGroups.begin(), atGateGroups.end());*/
}
