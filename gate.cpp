/*
gate.cpp

Gate object implementation file
*/

#include "gate.h"
#include "clock.h"
#include "time_observer.h" 
#include "passenger.h" 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Constructor
Gate::Gate(int gateID) : Objects_clock(Clock(0, 0, 0))
{
    this->Gate_ID = gateID;
    this->In_use = false;
    this->Plane_docked = false;
    this->Plane_ID = -1; // -1 indicates no plane docked
    this->Passengers_at_gate = 0;
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
bool Gate::getInUse() const
{
    return In_use;
}

bool Gate::getNowBoarding() const
{
    return In_use; // or adjust as needed
}

bool Gate::getPlaneDocked() const
{
    return Plane_docked;
}

int Gate::getPlane_ID() const
{
    return Plane_ID;
}

int Gate::getPassengersAtGate() const
{
    return Passengers_at_gate;
}

// Setters
void Gate::setInUse(bool inUse)
{
    In_use = inUse;
}

void Gate::setNowBoarding(bool nowBoarding)
{
    In_use = nowBoarding; // or adjust as needed
}

void Gate::setPlaneDocked(bool planeDocked)
{
    Plane_docked = planeDocked;
}

void Gate::setPlane_ID(int planeID)
{
    Plane_ID = planeID;
}

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
