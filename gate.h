#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <string>
#include <vector>
#include "clock.h" // Include the header for Clock class
#include "time_observer.h" // Include the header for TimeObserver class

class Clock {
    // Necessary for function but idk what to put
};

class Passenger {
    // Necessary for function but idk what to put
};

class Gate {
public:

    // Constructor
    Gate(int gateID);

    int Gate_ID; // Primary key/identifier for gate

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
    bool In_use; // Is the gate currently in the process of boarding or onboarding?

    Clock Objects_clock; // Instance of the clock object for the gate, used to keep simulation synchronization

    bool Plane_docked; // Is a plane currently docked at the gate?
    std::vector<Passenger> Passengers_at_gate;
    int Plane_ID; // Which plane is docked at/using the gate?
    int Passengers_at_gate; // The number of passengers currently at the gate. Number sent from the airport.

    // Getters
    bool getInUse() const; // Return In use var
    bool getNowBoarding() const; // Return whether currently boarding
    bool getPlaneDocked() const; // Return if it is docked
    int getPlane_ID() const; // Return plane ID
    int getPassengersAtGate() const; // Return how many passengers waiting at gate

    // Setters
    void setInUse(bool inUse); // Set in use variable
    void setNowBoarding(bool nowBoarding); // Set whether currently boarding
    void setPlaneDocked(bool planeDocked); // Set if the plane is docked
    void setPlane_ID(int planeID); // Set plane ID

    // Multi-action methods
    void board(const std::vector<Passenger>& passengers); // Call plane board option and send the passenger vector
    void disembark(); // Call disembark option on the plane and fill the passenger vector

};

#endif // GATE_H
