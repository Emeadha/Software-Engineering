/*
gate.cpp

Gate object implementation file
*/

#include "gate.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

// Constructor
Gate::Gate(int gateID) : Objects_clock(Clock(0, 0, 0))
{
    this->Gate_ID = gateID;
    this->In_use = false;
    this->Plane_docked = false;
    this->Plane_ID = -1; // -1 indicates no plane docked
}

// Gate observes or reacts to changes in time
void Gate::onTimeUpdate(Clock& new_time)
{
    // Start by setting done to false
    TimeObserver::setIsNotDone();

    // Update the clock of the gate
    Objects_clock = new_time;

    // Display a message indicating the time update
    cout << "Gate " << Gate_ID << " updated its time to "
         << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    // Say that we are done
    TimeObserver::setIsDone();
}

// Getters

int Gate::getGateID(){
    return Gate_ID;
}

bool Gate::getInUse()
{
    return In_use;
}

bool Gate::getPlaneDocked()
{
    return Plane_docked;
}

int Gate::getPlane_ID()
{
    return Plane_ID;
}

int Gate::getPassengersAtGate()
{
    return Passengers_at_gate.size();
}

// Setters
void Gate::setInUse(bool inUse)
{
    In_use = inUse;
}


void Gate::setPlaneDocked(bool planeDocked)
{
    Plane_docked = planeDocked;
}

void Gate::setPlane_ID(int planeID)
{
    Plane_ID = planeID;
}

/*Adds passenger groups to vector passengerGroups
void Gate::createPassengers(int groupID)
{
    for(int i = 0; i < 5; i++)
    {
        passengerGroups.push_back(groupID);
    }
    //clockDelay();
}

vector<passengerMovement>& Gate::getPassengerMovements()
{
    return passengerMovements;
}

void Gate::removePassengerMovement(int groupID)
{
    passengerMovements.erase(remove_if(passengerMovements.begin(), passengerMovements.end(), [&]
    (const passengerMovement& movement) { return movement.groupID == groupID; }), passengerMovements.end());
}
//Will create 6 gates to the gate vector
void Gate::createGates(int gateID)
{
    for(int i = 1; i <= 6; i++)
        gates.emplace_back(gateID);
}

//Will assign each of the passenger groups to 2 gates
void Gate::assignGates(vector<Passenger>& passengers)
{
    shuffle(gates.begin(), gates.end(), randomEngine);
    int gateCount = gates.size();
    int groupCount = passengers.size();

    for(int x = 0; x < groupCount; x++) 
    {
        int startGate = randomEngine() % gateCount;
        int targetGate = (startGate + 1 + (randomEngine() % (gateCount - 1)));

        for(int j = 0; j < 2; j++)
        {
            int gateID = (j == 0) ? startGate : targetGate;
            gates[gateID].createPassengers(passengers[x].Passenger_group_ID);
        }
         //initializing using parameters from struct
        passengerMovement movement;
        movement.groupID = passengers[x].Passenger_group_ID;
        movement.startGateID = startGate;
        movement.targetGateID = targetGate;
        //movement.remainingTime = trav el time
        passengerMovements.push_back(movement);
    }

}/*
    

/*
//Multi-action
void Gate::board(const std::vector<Passenger>& passengers)
{
    if (Plane_docked && In_use)
    {
        // Perform boarding actions
        cout << "Boarding plane " << Plane_ID << " at Gate " << Gate_ID << " with " << passengers.size() << " passengers." << endl;

        // Update passenger count and any other relevant information
        Passengers_at_gate += static_cast<int>(passengers.size()); // Convert size_t to int for compatibility
    }
    else
    {
        cout << "Unable to board. No plane docked or gate not in use." << endl;
    }
}

void Gate::disembark()
{
    if (Plane_docked && In_use)
    {
        // Perform disembarkation actions
        cout << "Disembarking passengers from plane " << Plane_ID << " at Gate " << Gate_ID << "." << endl;

        // Update passenger count and any other relevant information
        Passengers_at_gate = 0;
    }
    else
    {
        cout << "Unable to disembark. No plane docked or gate not in use." << endl;
    }
}
*/