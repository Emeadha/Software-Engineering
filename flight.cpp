/*
Flight.cpp

Flight implementation

(Real simple, I know)
*/
// Flight.cpp
#include "flight.h"

//Big ugly constructor
Flight::Flight(int Flight_ID, int Ticket_cost, string Flight_type, string Dest_airport_name,
        string Origin_airport_name, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec, double distance) 
        : Departure_time(D_hour,D_hour,D_sec), Arrival_time(A_hour,A_min,A_sec) {

        this->Flight_ID = Flight_ID;
        this->Ticket_cost = Ticket_cost;
        this->Flight_type = Flight_type; 
        this->Dest_airport_name = Dest_airport_name;
        this->Origin_airport_name = Origin_airport_name;
    
}

//Getters 
bool Flight::getScheduled(){
    return Scheduled;
}
int Flight::getPlaneID(){
    return Plane_ID;
}
int Flight::getDestAirptID(){
    return Dest_airport_ID;
}
int Flight::getOriginAirptID(){
    return Origin_airport_ID;
}
double Flight::getDistance(){
    return Distance;
}
Clock Flight::getArrivalTime(){
    return Arrival_time;
}
Clock Flight::getDepartureTime(){
    return Departure_time;
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
void Flight::setArrivalTime(Clock New_arrival_time){
    this->Arrival_time = New_arrival_time;
}
void Flight::setDepartureTime(Clock New_depature_time){
    this->Departure_time = New_depature_time;
}