/*
airline.cpp

*/
// Airline.cpp
#include "airline.h"

// Constructor
//We assign the time manager here, so we can use it to register new observers
Airline::Airline(TimeManager *time_manager, string airline_name) : time_manager(time_manager),  Objects_clock(0, 0, 0), flightLog("flightLog.txt") {
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

    //READ IN THEN SCHEDULE ALL FLIGHTS
    addFlightToVector();
    scheduleFlights();
}

//Destructor
Airline::~Airline(){
    //Close output file
    flightLog.close();
}

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


//Schedule flights
void Airline::scheduleFlights(){
    //Want to acsess flight vector, send out flight info to all objects like 
    // planes and airports, then flip scheduled boolean to true

            /*
            STEPS TO SCHEDULE FLIGHT
            1. Check and see if unscheduled
            2. Find out associated plane ID
            3. Check if plane is currently availible or already scheduled
            4. If so, Modify plane variables to accomodate flight
            5. Flip scheduled to true, and the planes availibility to false
            */

    //Move through vector, checking to see if its been scheduled, then schedule it
    //Set our temporary variables
    int i = 0, tempPlaneID = 0, tempDestID = 0;
    int planePositionInArray = 0;
    Clock tempArrivalTime, tempDepartTime;

    while (i < All_flights.size()){
        //Check to see if the flight has already been scheduled
        if(All_flights[i]->getScheduled() == false){

            //Get this flights temp. information 
            tempPlaneID = All_flights[i]->getPlaneID();

            //Find plane in question by searching through vector
            planePositionInArray = findPlanePosition(tempPlaneID);

            //Check to make sure plane exists in vector
            if(planePositionInArray == -1){
                cerr << "Error! Plane not found in plane registry" << endl;
            }
            else{
                //Check if plane is ready to receive a new assignment
                if(All_planes[planePositionInArray]->getIsReadyForAssignment()==true){
                    //Get our relevant information from flight
                    tempDestID = All_flights[i]->getDestAirptID();
                    tempArrivalTime = All_flights[i]->getArrivalTime();
                    tempDepartTime = All_flights[i]->getDepartureTime();

                    //Assign receieved values to plane, and set ready to assign as false
                    All_planes[planePositionInArray]->assignFlight(tempDestID, tempArrivalTime, tempDepartTime);

                    //Set this flight in vector to scheduled
                    All_flights[i]->setScheduledTrue();
                }
            }
            
            //Print creation to flight log
            flightLog << "Flight scheduled! Leaves from Arpt: " << All_flights[i]->getOriginAirptID() << " @" << tempDepartTime
            << " to Arpt: " << All_flights[i]->getDestAirptID() << " @" << tempArrivalTime << " PlaneID used: " << All_flights[i]->getPlaneID()
            << endl;


        }

        //Increment i
        i++;
    }
}

//Cycle through planes and return matching ID, or if failure -1
int Airline::findPlanePosition(int ID){

    //Iterator
    int i = 0;
    //Iterate through all planes, return position when found
    while (i < All_planes.size()){
        if(All_planes[i]->getPlaneID() == ID){
            return i;
        }
        else
            i++;
    }

    //If ID doesn't exist
    return -1;
}
void Airline::addFlightToVector(){
    // Want to read flight details from Timetable then add to vector (will be
    // harcoded at first)

    //FOUR FLIGHTS TOTAL ----- HARDCODED
    //Leaves at 5:00 AM from Airport 1 to Airport 2 at 7:00 AM
    Flight* flight = new Flight(100,1, "", "","",5,0,0,7,0,0);

    //Add to vector
    All_flights.push_back(flight);
    
}

void Airline::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    Objects_clock = new_time;
    cout << "Airport " << Airline_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Say that we are do3ne
    TimeObserver::setIsDone();
}
