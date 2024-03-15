/*
passenger.cpp

Passenger object implementation file
*/
// Passenger.cpp
#include "passenger.h"
#include <iostream>

Passenger::Passenger(int Passenger_group_ID) :  Objects_clock(0, 0, 0) {
    this->Passenger_group_ID = Passenger_group_ID;
}


//TEST CHANGE - To avoid conflicts, passenger no longer time observer
/*
void Passenger::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    Objects_clock = new_time;
    cout << "PassengerGroup " << Passenger_group_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Say that we are done
    TimeObserver::setIsDone();

    /*
    //Assigning start gate
    void Passenger::setStartGate(Gate* startGate)
    {
        startGate = gate;
    }

    //Assigning target gate
    void Passenger::setTargetGate(Gate* targetGate)
    {
        targetGate = gate; 
    }
}
*/