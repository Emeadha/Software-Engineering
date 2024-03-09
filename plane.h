/*
Plane.h


Plane- This object represents a single plane owned by the customer. It needs to
 have all the appropriate variables listed in the handout, i.e. Make/model and
 corresponding passenger capacities. Plane receives a vector of passengers from
 its origin gate, then flies to the next airport to unload this vector of
 passengers. On each time update, plane may be flying, waiting at a gate, or in
 maintenance. The expenses for each plane at the end of the day need to be
 recorded by the airline object.

Who makes this object? Airline

Is it a time observer? Yes

What’s its goal? Be scheduled for a flight, and transport passengers in between
Airports by interacting with gates.


Plane object header file
*/
// Plane.h
#ifndef PLANE_H
#define PLANE_H
#include "timeObserver.h"
#include <string>
#include <fstream>

using namespace std;

class Plane : public TimeObserver {
private:

    /* BEGIN VARIABLES */

    //Output file name
     ofstream flightLog;

    //Basic plane attributes
    int Plane_ID; //The ID number of the plane (Primary Key)
    string Plane_model; //The make of the plane, e.g. “Boeing 757”
    Clock Objects_clock; //Instance of the clock object for the plane, used to keep simulation synchronization
    Clock Arrival_time;
    Clock Departure_time;

    //Fuel and travel variables
    float Fuel_tank; //How much fuel does the plane have remaining?
    float Max_fuel; //How much fuel can the plane hold at maximum?
    float Burn_rate; //How much fuel does the plane use up? Liters per kilometer.
    float Current_velocity; //KM per hour
    float Max_velocity; //Maximum velocity in KM/hour, ideal velocity i.e. what the plane can be expected to spend most of a flight at when not in takeoff/landing is 90% of this.

    //Plane Status 
    bool isFlying; //This is the status of the plane. Declared True if the plane has taken off. False if the plane is not flying
    bool isGrounded; //This is the status of the plane if its grounded or has not taken off.
    bool isMaintenance; //This is the maintenance status of the plane
    bool isWaiting; //This is the waiting status of the plane 
    bool isBoarding; //This is the boarding status of the plane
    bool isUnboarding; //This is the unboarding status of the plane. 
     //Availability bools
    bool Is_ready_for_assignment; //Is the plane ready for next scheduler assignment?
    bool Is_operable; //Can the plane currently be used for transport?
    bool Is_seats_open; //Is the plane not completely full of passengers?

    //Travel distance trackers
    double Odometer; //How many miles the plane has flown, in total.
    double Trip_odometer; //How many miles the plane has flown in its current flight.
    double Until_maint; //How long until the plane needs maintenance. Starts at 200 (hours of flight time).

    //Passenger variables
    int Max_passengers;//How many passengers the plane can carry
    int Onboard; //Count of passengers //TODO: Make this *actually* a passenger vector, not just an int
    int Count_of_passengers; // Number of passengers onboard

    //Costs
    double Daily_cost; //The overall cost to operate a plane, per day, in USD. Includes loan cost, fuel cost etc. Calculated by calcCost.
    double Loan_cost; //The amount of the loan cost per plane per month. Paid even if the plane is not in usage.
 
    //Location, origin, destination
    double Range; //KILOMETERS of travel possible remaining
    int Origin_airport_ID; //The airport the plane is starting from on a flight.
    int Target_airport_ID; //The airport the plane is scheduled to land at next.
    double Target_airport_location_distance; // Km to reach airport
    int Target_gate; //The gate of the targeted airport at which the plane is scheduled to land. 
    /* END VARIABLES */


public:

    /* BEGIN GETTERS */
    int getPlaneID(); //Returns PlaneID
    double getMaintenance(); //Returns Until_maintenance
    double getOdometer(); //Returns Odometer
    double getTripOdometer(); //Returns Trip_odometer
    bool getIsReadyForAssignment(); //Checks if Is_transit is true
    bool getIsOperable(); //Checks if Is_operable is true
    bool getIsSeatsOpen(); //Checks if Is_seats_open is true
    string getLocation(); //Returns distance from target airport //TODO: This should be a location object, set as a string for now for ease-of-testing other functions
    float getFuelLevel(); //Returns Fuel_tank
    double getDailyCost(); //Returns Daily_cost
    int getTargetGate(); //Returns the value of Target_gate
    int getTargetAirport();  //Returns the value of Target_airport
    int getPassengerCount(); //Returns the number of passengers in Onboard

    /* BEGIN SETTERS */
    void resetTripOdometer(); //Sets Trip_odometer to 0
    void setIsReadyForAssignment(bool isReady); //Set ready/not ready for next assignment
    void setFuelTank(float fuel); //Sets Fuel_Tank to a specific value.
    void refuelToFull(); //Sets Fuel_Tank to be equal to Max_fuel
    void setArrivalTime(Clock newTime); //Set clock object for arrival time
    void setDepartureTime(Clock newTime);//Set clock for departure time

    void setTargetGate(int gateID); //Sets the value of Target_gate
    void setTargetAirport(int airportID); //Sets the value of Target_airport
    void boardPassengers(int passengers); //Add all passengers waiting to board to Onboard. This should be called by the airport. //TODO: Currently set as an int for prototyping purposes, needs to be changed to vector of passenger objects at some point
    int disembarkPassengers(); //Remove all passengers from Onboard. Called by the airport //TODO: Currently set as an int for prototyping purposes, needs to be changed to a vector of passenger objects at some point..
    /* END SETTERS */

    /* BEGIN MISCELLANEOUS FUNCTIONS */
    void landAndDock(); //Docks plane at airport, requests passenger operations, fuel operations
    double calcCost(); //Calculates the value of Daily Cost, takes in information from fuel cost, loan etc.
    void fly(); //On each given tick and only if In_transit is true, progress towards the target airport’s location by amount specified by velocity variable. This method will affect the values of many variables such as fuel level, odometer, distance to target airport, etc.
    void doMaintenance(); //Sets Is_operable to false for 1.5 days (36 hours/2160 minutes), then sets Is_operable to true and resets Until_maintencance to 200
    /* END MISCELLANEOUS FUNCTIONS */

    //Constructor/destructor
    Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, float Max_velocity, int Max_passengers, float Current_velocity, double Odometer);
    ~Plane();

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;

    virtual void takeOff();// The takeoff method. Checking to see if plane is flying 
    virtual void onLanding(); // The landing method. Called when the plane is not flying 
    


    // The Checkfuel level method. It will check the fuel level and update the fuel level.
    virtual void checkFuelLevel(double duration, double miles);

    
};

#endif // PLANE_H

//TODO: Add origin airport ID, don't worry about timings
