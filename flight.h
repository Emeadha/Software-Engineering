/*
Flight.h

Flight  - Essentially, flight is the basic idea of a plane going to an airport
from an airport, at a certain time, at a certain gate. This object will be made
by the scheduler, and used as a basic unit for things like recalculation. It
will be given to an airport, so as to allow for communication and consistency.

Who makes this object? Values are read in from the time table into Airline,
which puts them in a vector.

Is it a time observer? No

What’s its goal? Hold the base value of one flight, meaning one trip in between
two airports, and the information such as ticket cost associated with it.


*/
// Flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

#include "clock.h"
#include <string>

class Flight {
private:

    //Basic details that make up a flight
    //Assigned during construction
    int Flight_ID = 0; //The number that identifies the flight
    float Ticket_cost = 0; //The cost of a ticket for a flight (currently all tickets for a given flight are the same price)
    string Flight_type = ""; //TODO: What is this?
    string Dest_airport_name = ""; //The name of the airport where a flight ends
    string Origin_airport_name = ""; //The name of the airport where a flight begins
    Clock Departure_time; //Scheduled departure time
    Clock Arrival_time; //Estimated arrival time at origin airport/gate

    double Distance;

    //Calculated during scheduling
    int Dest_airport_ID = 0; //The ID number of the airport for the plane to land at
    int Origin_airport_ID = 0; //The airport that a plane starts at when a flight begins
    int D_gate_ID = 0; //Destination gate at target airport
    int O_gate_ID = 0; //Origin gate at origin airport
    int Plane_ID = 0; //The ID number of the plane used for a flight
    // EVENTUALLY MOVE HERE double Distance;
    

    // Has this already been scheduled?
    bool Scheduled = false;

public:

    // Constructor
    Flight(int Ticket_cost, int Flight_ID, string Flight_type, string Dest_airport_ID, string Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec, double distance);
    
    //Getters
    //ADD MORE GETTERS HERE
    bool getScheduled(); //Returns whether the flight has been given a time to begin
    int getPlaneID(); //Return plane ID
    int getDestAirptID(); //Return target airport ID
    int getOriginAirptID(); //Return origin airport ID
    double getDistance();
    Clock getArrivalTime(); //Return estimated arrival time at target airport
    Clock getDepartureTime(); //Returns scheduled departure time from origin 

    //find way to set clock times with an override function

    //Setters
    //ADD MORE SETTERS HERE
    void setPlaneID(int Plane_ID); //Sets the ID number of the plane to be used for the flight
    void setOGateID(int O_gate_ID); //Sets gate for the flight to depart from
    void setDGateID(int D_gate_ID); //Sets gate for the flight to arrive at
    void setDistance(int Distance); //Sets distance to fly
    void setArrivalTime(Clock New_arrival_time); //Sets estimated arrival time
    void setDepartureTime(Clock New_departure_time); //Sets scheduled departure time

    void setScheduledFalse(); //Sets “Scheduled" variable to false
    void setScheduledTrue(); //Sets “Scheduled" variable to true

};

#endif // Flight_H
