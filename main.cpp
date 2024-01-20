/*
clock.cpp

Clock implementation

(Real simple, I know)
*/
// Clock.cpp
// main.cpp
#include "timeManager.h"
#include "plane.h"
#include "airport.h"
#include "passenger.h"
#include <thread>

int main() {
    TimeManager time_manager;

    Plane plane("Flight 123");
    Airport airport("International Airport");
    Passenger passenger("John Doe");

    // Register objects as observers
    time_manager.addObserver(&plane);
    time_manager.addObserver(&airport);
    time_manager.addObserver(&passenger);

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
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}