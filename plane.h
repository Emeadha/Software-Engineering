/*
Plane.h

Plane object header file
*/
// Plane.h
#ifndef PLANE_H
#define PLANE_H
#include "TimeObserver.h"
#include <string>

using namespace std;

class Plane : public TimeObserver {
public:
    //Basic plane attributes
    int Plane_ID;
    string Plane_model;
    Clock Objects_clock;

    //Fuel and travel variables
    float Fuel_tank;
    float Max_fuel;
    float Burn_rate;
    float Current_velocity;
    float Max_velocity;


    double Odometer;

    //Passenger variables
    int Max_passengers;


    Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, float Max_velocity, int Max_passengers, float Current_velocity, double Odometer);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // PLANE_H
