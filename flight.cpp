/*
Flight.cpp

Flight implementation

(Real simple, I know)
*/
// Flight.cpp
#include "flight.h"

//Big ugly constructor
Flight::Flight(int Flight_ID, double Ticket_cost, string Flight_type, string plane_name, string Dest_airport_name,
        string Origin_airport_name, int D_hour, int D_min, int D_sec, int A_hour, int A_min, int A_sec, double distance) 
        : Departure_time(D_hour,D_hour,D_sec), Arrival_time(A_hour,A_min,A_sec) {

        //lock_guard<mutex> lock(Flight_Con_Mutex);

        this->Flight_ID = Flight_ID;
        this->Ticket_cost = Ticket_cost;
        this->Flight_type = Flight_type; 
        this->Plane_name = plane_name;
        this->Dest_airport_name = Dest_airport_name;
        this->Origin_airport_name = Origin_airport_name;
        this->Distance = distance;

        if(debugging){
            cerr << "DEBUGGING: New flight object made, values of: ID:" << Flight_ID << " Ticket:" << Ticket_cost
                << " FlightType:" << Flight_type << " Planename:" << Plane_name << " Dest:" << Dest_airport_name
                << " Origin:" << Origin_airport_name << " Dist:" << distance << endl;
        }
    
}

//Getters 
bool Flight::getScheduled(){
    return Scheduled;
}
string Flight::getPlaneName(){
    return Plane_name;
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
string Flight::getDestAirptName(){
    return Dest_airport_name;
}
string Flight::getOriginAirptName(){
    return Origin_airport_name;
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
void Flight::setDestAirptID(int Dest_airport_ID){
    this->Dest_airport_ID = Dest_airport_ID;
}
void Flight::setOriginAirptID(int Origin_airport_ID){
    this->Origin_airport_ID = Origin_airport_ID;
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