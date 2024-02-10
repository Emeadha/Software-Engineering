/*
Flight.h

Basic time formatting, will be called by other classes
*/
// Flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

#include "clock.h"

class Flight {
public:

    //Basic details that make up a flight
    int Dest_airport_ID;
    int Origin_airport_ID;
    Clock Departure_time;
    Clock Arrival_time;

    // Has this already been scheduled?
    bool scheduled = false;

    // Constructor
    Flight(int Dest_airport_ID, int Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec);
};

#endif // Flight_H