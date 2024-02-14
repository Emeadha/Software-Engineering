/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "plane.h"
#include <iostream>


Plane::Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, float Max_velocity, int Max_passengers, float Current_velocity, double Odometer) : Objects_clock(0, 0, 0) {

    //Set the plane's attributes
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
    this->In_transit = In_transit;
    this->Is_operable = Is_operable;
    this->Is_seats_open = Is_seats_open;
    this->Daily_cost = Daily_cost;
    this->Loan_cost = Loan_cost;
    this->Range = Range;
    this->Origin_airport_ID = Origin_airport_ID;
    this->Target_airport_ID = Target_airport_ID;
    this->Target_airport_location_distance = Target_airport_location_distance;
    this->Target_gate;
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
