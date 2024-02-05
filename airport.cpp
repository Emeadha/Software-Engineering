/*
airport.cpp

*/
// Airport.cpp
#include "airport.h"



Airport::Airport(TimeManager *time_manager, string airport_name) : time_manager(time_manager), Objects_clock(0, 0, 0) {
    this->Airport_name = airport_name;

    // Create passenger and gate objects
    for(int i = 0; i < 5; i++) {
        Passenger* passenger_group = new Passenger(i);
        //Register passenger group
        registerPassengerGroup(passenger_group);
    }
}

//Register a passenger_group (to vector) and as an observer
void Airport::registerPassengerGroup(Passenger* passenger_group){
    time_manager->addObserver(passenger_group);
    All_passenger_groups.push_back(passenger_group);
}

//When time gets updated
void Airport::onTimeUpdate(Clock& new_time) {
    Objects_clock = new_time;
    cout << "Airport " << Airport_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
}