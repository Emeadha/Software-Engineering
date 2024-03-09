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

class Flight {
private:

    //Basic details that make up a flight
    float Ticket_cost = 0;
    int Flight_ID = 0;
    int Plane_ID = 0;
    int Dest_airport_ID = 0;
    int Origin_airport_ID = 0;
    int D_gate_ID = 0;
    int O_gate_ID = 0;
    double Distance = 0;
    Clock Departure_time;
    Clock Arrival_time;

    // Has this already been scheduled?
    bool Scheduled = false;

public:

    // Constructor
    Flight(int Ticket_cost, int Flight_ID, int Dest_airport_ID, int Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec);
    
    //Getters
    //ADD MORE GETTERS HERE
    bool getScheduled();
    int getPlaneID();
    int getDestAirptID();
    int getOriginAirptID();
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