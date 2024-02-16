/*
Flight.cpp

Flight implementation

(Real simple, I know)
*/
// Flight.cpp
#include "flight.h"

//Big ugly constructor
Flight::Flight(int Ticket_cost, int Flight_ID, int Dest_airport_ID, int Origin_airport_ID, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec) 
    : Departure_time(D_hour,D_hour,D_sec), Arrival_time(A_hour,A_min,A_sec) {
        this->Ticket_cost = Ticket_cost;
        this->Dest_airport_ID = Dest_airport_ID;
        this->Origin_airport_ID = Origin_airport_ID;
}

//Getters 
bool Flight::getScheduled(){
    return Scheduled;
}


//Setters
void Flight::setPlaneID(int Plane_ID){
    this->Plane_ID = Plane_ID;
}
void Flight::setOGateID(int O_gate_ID){
    this->O_gate_ID = O_gate_ID;
}
void Flight::setDGateID(int D_gate_ID){
    this->D_gate_ID = D_gate_ID;
}
void Flight::setDistance(int Distance){
    this->Distance = Distance;
}
void Flight::setScheduledTrue(){
    this->Scheduled = true;
}
void Flight::setScheduledFalse(){
    this->Scheduled = false;
}