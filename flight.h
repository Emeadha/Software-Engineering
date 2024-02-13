/*
Flight.h

Basic time formatting, will be called by other classes
*/
// Flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

#include "clock.h"

class Flight {
private:

    //Basic details that make up a flight
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
    Flight(int Flight_ID, int Dest_airport_ID, int Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec);
    
    //Getters
    //ADD MORE GETTERS HERE
    bool getScheduled();

    //Setters
    //ADD MORE SETTERS HERE
    void setPlaneID(int Plane_ID);
    void setOGateID(int O_gate_ID);
    void setDGateID(int D_gate_ID);
    void setDistance(int Distance);

    void setScheduledFalse();
    void setScheduledTrue();

};

#endif // Flight_H