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

    //Airport airport("International Airport");
    //Passenger passenger("John Doe");

    //At first, we only create our Airline
    // Airline -> Airports + Planes
    // Airports -> Gates + Passengers
    Airline airline(&time_manager, "Comfort Airlines");

    // Register objects as observers
    //time_manager.addObserver(&passenger);

    // Start simulation
    time_manager.startSimulation();
/*
    //THIS IS THE MAIN SIMULATION LOOP FOR TIME
    //24 hours = 1440 minutes
    //Each iteration is 10 minutes
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    for(int i = 0; i < 144; i++){
        // Hold values of hours, minutes, and seconds,
        // if minutes exceeds 60 add 1 to hours and reset minutes to 0
        minutes += 10;
        if(minutes >= 60){
            hours++;
            minutes = 0;
        }

        time_manager.updateSimulationTime(hours, minutes, 0);

        // Sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }
*/
    return 0;
}
