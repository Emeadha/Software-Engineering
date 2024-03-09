/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "Plane.h"
#include <iostream>
using namespace std;

// hello

Plane::Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, 
    float Max_velocity, int Max_passengers, float Current_velocity, 
    double Odometer) : Objects_clock(0, 0, 0), flightLog("flightLog.txt"){

    //Set the plane's attributess
    this->Plane_ID = Plane_ID;
    this->Plane_model = plane_name;
    this->Fuel_tank = Fuel_tank;
    this->Max_fuel = Max_fuel;
    this->Burn_rate = Burn_rate;
    this->Current_velocity = Current_velocity;
    this->Max_velocity = Max_velocity;
    this->Max_passengers = Max_passengers;
    this->Onboard = Onboard;
    this->Count_of_passengers = Count_of_passengers;
    this->Current_velocity = Current_velocity;
    this->Odometer = Odometer;
    this->Trip_odometer = Trip_odometer;
    this->Until_maint = Until_maint;
    this->Is_ready_for_assignment = true;
    this->Is_operable = Is_operable;
    this->Is_seats_open = Is_seats_open;
    this->Daily_cost = Daily_cost;
    this->Loan_cost = Loan_cost;
    this->Range = Range;
    this->Origin_airport_ID = Origin_airport_ID;
    this->Target_airport_ID = Target_airport_ID;
    this->Target_airport_location_distance = Target_airport_location_distance;
    this->Target_gate;
    this->isFlying = false;
    this->isGrounded = true;
    this->isMaintenance;
    this->isWaiting;
    this->isBoarding;
    this->isUnboarding;

    //Don't worry about this but eventually will want way to print to log
    //flightLog << "Plane " << this->Plane_ID << " created. Model: " << this->Plane_ID << endl;

}

//Destructor
Plane::~Plane(){
    //Close output file
    flightLog.close();
}
void Plane::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    //Update the plane's time
    Objects_clock = new_time;
    //Debugging statement
    cout << "Plane " << Plane_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
    //cout << "Variables: " << Plane_model << " " << Max_fuel << " " << Burn_rate << " " << Max_passengers << " " << Current_velocity << " " << Odometer << endl;

    //Say that we are done
    TimeObserver::setIsDone();
}
void Plane::takeOff(){
    isFlying = true;
    cout << " the plane is flying" << endl;


}
   /* BEGIN GETTERS */

int Plane::getPlaneID(){
    return this->Plane_ID;
}
double Plane::getMaintenance()
{

    return this->Until_maint;
}

double Plane::getOdometer()
{

    return this->Odometer;
}

double Plane::getTripOdometer()
{

    return this->Trip_odometer;
}

bool Plane::getIsReadyForAssignment()
{

    return this->Is_ready_for_assignment;
}

bool Plane::getIsOperable()
{

    return this->Is_operable;
}

bool Plane::getIsSeatsOpen()
{

    return this->Is_seats_open;
}

string Plane::getLocation() //TODO: This needs to return an actual location
{

    return "TEMPLATE";
}

float Plane::getFuelLevel()
{

    return this->Fuel_tank;
}

double Plane::getDailyCost()
{

    return this->Daily_cost;
}

int Plane::getTargetGate()
{

    return this->Target_gate;
}

int Plane::getTargetAirport()
{

    return this->Target_airport_ID;
}

int Plane::getPassengerCount()
{

    return this->Count_of_passengers;
}
   /* END GETTERS */

   /* BEGIN SETTERS*/
void Plane::setArrivalTime(Clock newTime){
        this->Arrival_time = newTime;
}

void Plane::setDepartureTime(Clock newTime){
        this->Departure_time = newTime;
}
void Plane::setIsReadyForAssignment(bool isReady){
    this->Is_ready_for_assignment = isReady;
}
void Plane::setTargetAirport(int airportID){
    this->Target_airport_ID = airportID;
}

    /* END SETTERS*/