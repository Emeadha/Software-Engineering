/*
Plane.h

Plane object header file
*/
// Plane.h
#ifndef PLANE_H
#define PLANE_H
#include "timeObserver.h"
#include <string>

using namespace std;

class Plane : public TimeObserver {
public:
    //Basic plane attributes
    int Plane_ID; //The ID number of the plane (Primary Key)
    string Plane_model; //The make of the plane, e.g. “Boeing 757”
    Clock Objects_clock; //Instance of the clock object for the plane, used to keep simulation synchronization

    //Fuel and travel variables
    float Fuel_tank; //How much fuel does the plane have remaining?
    float Max_fuel; //How much fuel can the plane hold at maximum?
    float Burn_rate; //How much fuel does the plane use up? Liters per kilometer.
    float Current_velocity; //KM per hour
    float Max_velocity; //Maximum velocity in KM/hour, ideal velocity i.e. what the plane can be expected to spend most of a flight at when not in takeoff/landing is 90% of this.

    //Travel distance trackers
    double Odometer; //How many miles the plane has flown, in total.
    double Trip_odometer; //How many miles the plane has flown in its current flight.
    double Until_maint; //How long until the plane needs maintenance. Starts at 200 (hours of flight time).

    //Passenger variables
    int Max_passengers;//How many passengers the plane can carry
    int Onboard; //Count of passengers //TODO: Make this *actually* a passenger vector, not just an int
    int Count_of_passengers; // Number of passengers onboard

    //Availability bools
    bool In_transit; //Is the plane in flight?
    bool Is_operable; //Can the plane currently be used for transport?
    bool Is_seats_open; //Is the plane not completely full of passengers?

    //Costs
    double Daily_cost; //The overall cost to operate a plane, per day, in USD. Includes loan cost, fuel cost etc. Calculated by calcCost.
    double Loan_cost; //The amount of the loan cost per plane per month. Paid even if the plane is not in usage.
 
    //Location, origin, destination
    double Range; //KILOMETERS of travel possible remaining
    int Origin_airport_ID; //The airport the plane is starting from on a flight.
    int Target_airport_ID; //The airport the plane is scheduled to land at next.
    double Target_airport_location_distance; // Km to reach airport
    int Target_gate; //The gate of the targeted airport at which the plane is scheduled to land. 

    Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, float Max_velocity, int Max_passengers, float Current_velocity, double Odometer);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // PLANE_H

//TODO: Add origin airport ID, don't worry about timings
