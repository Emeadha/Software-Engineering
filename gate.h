/*
gate.h

Gate object header file

Gate - The basic intermediary for the airport, holds things like passenger
count, flight and whether the plane is docked. Gate will not initiate
interactions, but instead be called by either plane or airport.

Who makes this object? Airport

Is it a time observer? Yes

What’s its goal? To act as an intermediary in between Airports and Planes for
transporting passenger groups.

*/
#ifndef GATE_H
#define GATE_H

#include "timeObserver.h"

#include <iostream>

#include <string>
#include <iomanip>
#include <vector>
#include "passenger.h"
#include "clock.h" // Include the header for Clock class
#include "timeObserver.h" // Include the header for TimeObserver class

using namespace std;

class Gate : public TimeObserver{

private:

    int Gate_ID; // Primary key/identifier for gate
    bool In_use; // Is the gate currently in the process of boarding or onboarding?
    bool Plane_docked; // Is a plane currently docked at the gate?

    Clock Objects_clock; // Instance of the clock object for the gate, used to keep simulation synchronization

    vector<Passenger> Passengers_at_gate; // The number of passengers currently at the gate. Number sent from the airport.
    int Plane_ID; // Which plane is docked at/using the gate?

public:

    // Constructor
    Gate(int gateID);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    // Getters
    int getGateID(); // Return Gate ID (primary key)
    bool getInUse(); // Return In use var
    bool getPlaneDocked(); // Return if it is docked
    int getPlane_ID(); // Return plane ID
    int getPassengersAtGate(); // Return size of vector

    // Setters
    void setInUse(bool inUse); // Set in use variable
    void setPlaneDocked(bool planeDocked); // Set if the plane is docked
    void setPlane_ID(int planeID); // Set plane ID

    // Multi-action methods
    //void board(vector<Passenger>& passengers); // Call plane board option and send the passenger vector
    //void disembark(); // Call disembark option on the plane and fill the passenger vector

};

#endif // GATE_H
