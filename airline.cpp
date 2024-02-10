/*
airline.cpp

*/
// Airline.cpp
#include "Airline.h"

// Constructor
//We assign the time manager here, so we can use it to register new observers
Airline::Airline(TimeManager *time_manager, string airline_name) : time_manager(time_manager),  Objects_clock(0, 0, 0) {
    this->Airline_name = airline_name;

    // ---------------------
    // Create/Register objects
    // ---------------------

    //Making plane objects
    //Currently, we are creating 5 planes
    //In the future, we want this to be read in by a file
    for(int i = 0; i < 5; i++) {
        Plane* plane = new Plane(i, "Boeing 747", 26020, 3217, 749.7, 172, 0, 0);
        //Test register plane
        registerPlane(plane);
    }

    string airport_name;
    for(int i = 0; i < 2; i++) {
        //Just for now, want to have new airports labeled this way
        airport_name = "New airport" + to_string(i);
        // Want to pass airport the time manager too, so it can register gates and passengers
        Airport* airport = new Airport(time_manager, airport_name);
        //Test register plane
        registerAirport(airport);
    }
   
}

//Destructor
Airline::~Airline(){}

//Register a plane as an observer, AND adds it to the list of planes
void Airline::registerPlane(Plane* plane) {
    time_manager->addObserver(plane);
    All_planes.push_back(plane);
}

//Register an airport likewise
void Airline::registerAirport(Airport* airport) {
    time_manager->addObserver(airport);
    All_airports.push_back(airport);
}

void Airline::scheduleFlight(){
    //Want to acsess flight vector, send out flight info to all objects like 
    // planes and airports, then flip scheduled boolean to true
}

void Airline::addFlightToVector(){
    // Want to read flight details from Timetable then add to vector (will be
    // harcoded at first)
    
}

void Airline::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    Objects_clock = new_time;
    cout << "Airport " << Airline_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Say that we are done
    TimeObserver::setIsDone();
}