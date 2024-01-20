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

int main() {
    TimeManager time_manager;

    Plane plane("Flight 123");
    Airport airport("International Airport");
    Passenger passenger("John Doe");

    // Register objects as observers
    time_manager.addObserver(&plane);
    time_manager.addObserver(&airport);
    time_manager.addObserver(&passenger);

    // Update simulation time
    time_manager.updateSimulationTime(1, 30, 0);

    return 0;
}