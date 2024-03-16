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
    int Flight_ID = 0;
    float Ticket_cost = 0;
    string Flight_type = "";
    string Dest_airport_name = "";
    string Origin_airport_name = "";
    Clock Departure_time;
    Clock Arrival_time;

    double Distance;

    //Calculated during scheduling
    int Dest_airport_ID = 0;
    int Origin_airport_ID = 0;
    int D_gate_ID = 0;
    int O_gate_ID = 0;
    int Plane_ID = 0;
    // EVENTUALLY MOVE HERE double Distance;
    

    // Has this already been scheduled?
    bool Scheduled = false;

public:

    // Constructor
    Flight(int Ticket_cost, int Flight_ID, string Flight_type, string Dest_airport_ID, string Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec, double distance);
    
    //Getters
    //ADD MORE GETTERS HERE
    bool getScheduled();
    int getPlaneID();
    int getDestAirptID();
    int getOriginAirptID();
    double getDistance();
    Clock getArrivalTime();
    Clock getDepartureTime();

    //find way to set clock times with an override function

    //Setters
    //ADD MORE SETTERS HERE
    void setPlaneID(int Plane_ID);
    void setOGateID(int O_gate_ID);
    void setDGateID(int D_gate_ID);
    void setDistance(int Distance);
    void setArrivalTime(Clock New_arrival_time);
    void setDepartureTime(Clock New_departure_time);

    void setScheduledFalse();
    void setScheduledTrue();

};

#endif // Flight_H