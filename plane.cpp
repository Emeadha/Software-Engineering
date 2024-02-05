/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "Plane.h"
#include <iostream>


Plane::Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, float Max_velocity, int Max_passengers, float Current_velocity, double Odometer) : Objects_clock(0, 0, 0) {

    //Set the plane's attributes
    this->Plane_ID = Plane_ID;
    this->Plane_model = plane_name;
    this->Max_fuel = Max_fuel;
    this->Burn_rate = Burn_rate;
    this->Max_velocity = Max_velocity;
    this->Max_passengers = Max_passengers;
    this->Current_velocity = Current_velocity;
    this->Odometer = Odometer;
}

void Plane::onTimeUpdate(Clock& new_time) {
    //Update the plane's time
    Objects_clock = new_time;
    //Debugging statement
    cout << "Plane " << Plane_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
    //cout << "Variables: " << Plane_model << " " << Max_fuel << " " << Burn_rate << " " << Max_passengers << " " << Current_velocity << " " << Odometer << endl;
}