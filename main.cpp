/*
main.cpp

Descr: This file is the main file for the sim, it is responsible for creating
a TimeManager and Airline object. It also updates TimeManager by controlling
the tick-rate (currently every 10 min is 1 second for sim).
*/


// main.cpp
#include "timeManager.h"
#include "plane.h"
#include "airport.h"
#include "passenger.h"
#include "airline.h"
#include <thread>

using namespace std;

int main() {
    //This is our time manager, which will be passed to all objects	
    TimeManager time_manager;

    // Create objects

    //At first, we only create our Airline
    // Airline -> Airports + Planes
    // Airports -> Gates + Passengers
    Airline airline(&time_manager, "Comfort Airlines");


    // Start simulation
    time_manager.startSimulation();

    return 0;
}
