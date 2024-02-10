/*
Flight.cpp

Flight implementation

(Real simple, I know)
*/
// Flight.cpp
#include "flight.h"

//Big ugly constructor
Flight::Flight(int Dest_airport_ID, int Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec) 
    : Departure_time(D_hour,D_hour,D_sec), Arrival_time(A_hour,A_min,A_sec) {
        this->Dest_airport_ID = Dest_airport_ID;
        this->Origin_airport_ID = Origin_airport_ID;
}