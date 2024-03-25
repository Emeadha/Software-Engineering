/*
airline.cpp

*/
// Airline.cpp
#include "airline.h"

// Constructor
//We assign the time manager here, so we can use it to register new observers
Airline::Airline(TimeManager *time_manager, string airline_name, Input Input_object, Logger *Log_object)
        : time_manager(time_manager),  Objects_clock(0, 0, 0), flightLog("flightLog.txt"), Input_object(Input_object)
        , Log_object(Log_object) {
    this->Airline_name = airline_name;

    // ---------------------
    // Receive from input object/Register objects
    // ---------------------

    //Get plane vector from input object
    All_planes = Input_object.get_plane_vector();
    for(int j=0; j<All_planes.size(); j++){
        //Register with time manager
        registerPlane(All_planes[j]);
    }

    //Get airport vector from input object
    All_airports = Input_object.get_airport_vector();
    for(int j=0; j<All_airports.size(); j++){
        //register with time manager
        registerAirport(All_airports[j]);
    }

    //Load flights and fill in missing info based off airport and plane data
   loadFlights();

    //Go ahead and schedule flights now
    scheduleFlights();
}

//Destructor
Airline::~Airline(){
    //Close output file
    flightLog.close();
}

//Register a plane as an observer
void Airline::registerPlane(Plane* plane) {
    //Add this object as an observer
    time_manager->addObserver(plane);
}

//Register an airport likewise
void Airline::registerAirport(Airport* airport) {
    //Add this object as an observer
    time_manager->addObserver(airport);

    cerr << "LOGGER - Filling logger slot" << endl;
    //Fill its logger slot
    airport->setLogObject(Log_object);
}


//Schedule flights
void Airline::scheduleFlights(){
    //Want to acsess flight vector, send out flight info to all objects like 
    // planes and airports, then flip scheduled boolean to true

    //Move through vector, checking to see if its been scheduled, then schedule it
    //Set our temporary variables
    int i = 0, tempPlaneID = 0, tempDestID = 0;
    int planePositionInArray = 0;
    Clock tempArrivalTime, tempDepartTime;
    double tempDistance;

    while (i < All_flights.size()){
        //Check to see if the flight has already been scheduled
        if(All_flights[i]->getScheduled() == false){

            //STEPS
            //1. Get plane ID from flight vector
            //2. Iterate through all unscheduled flights
            //2.5 (We only want to grab unscheduled flights with a plane that isn't busy)
            //3. Get nessesary info from flight
            //4. Assign to plane
            //5. Flip to scheduled (assignFlight takes care of saying the plane itsef is scheduled)

            //Start by grabbing planeID from flight
            tempPlaneID = All_flights[i]->getPlaneID();

            //Check to make sure plane exists in vector
            if(tempPlaneID == -1){
                cerr << "Error! Plane not found in plane registry" << endl;
            }
            else{
                //Check if plane is ready to receive a new assignment
                if(All_planes[tempPlaneID]->getIsReadyForAssignment()==true){
                    //Get our relevant information from flight
                    tempDestID = All_flights[i]->getDestAirptID();
                    tempArrivalTime = All_flights[i]->getArrivalTime();
                    tempDepartTime = All_flights[i]->getDepartureTime();
                    tempDistance = All_flights[i]->getDistance();

                    //Assign receieved values to plane, and set ready to assign as false
                    All_planes[tempPlaneID]->assignFlight(tempDestID, tempArrivalTime, tempDepartTime, tempDistance);

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
int Airline::findPlaneID(string plane_name){

    //Iterator
    int i = 0;

    if(debugging)
    {
        cout << "DEBUGGING: findPlaneID, plane_name = " << plane_name << endl;
    }

    //Iterate through all planes, return position when found
    while (i < All_planes.size()){

        if(debugging)
        {
            cout << "DEBUGGING: getPlaneName() call returns: " << All_planes[i]->getPlaneName() << ", Index: " << i << endl;
        }


        if(All_planes[i]->getPlaneName() == plane_name){

            if(debugging)
            {
                cout << "DEBUGGING: Found! Plane name: " << All_planes[i]->getPlaneName() << ", Index: " << i << endl;
            }

            return i;
        }
        else
            i++;
    }

    //If ID doesn't exist
    return -1;
}
int Airline::findAirportID(string airport_name){
    //Iterator
    int i = 0;

    if(debugging)
    {
        cout << "DEBUGGING: findAirportID, airport_name = " << airport_name << endl;
    }

    //Iterate through all planes, return position when found
    while (i < All_airports.size()){

        if(debugging)
        {
            cout << "DEBUGGING: getAirportName() call returns: " << All_airports[i]->getAirportName() << ", Index: " << i << endl;
        }


        if(All_airports[i]->getAirportName() == airport_name){
            
            if(debugging)
            {
                cout << "DEBUGGING: Found! Airport name: " << All_airports[i]->getAirportName() << ", Index: " << i << endl;
            }
            
            return i;
            
        }
        else
            i++;
    }


    //If ID doesn't exist
    return -1;
}
void Airline::loadFlights(){

    //Variable holders
    string temp_name = "";
    int tempID = -1;

    //Get flight vector from input object
    All_flights = Input_object.get_flight_vector();

    //Calculate remaining information based on airport and plane data
    for(int i=0; i<All_flights.size(); i++){
        //Debugging statement
        if(debugging){
            cout << "DEBUGGING: " << All_flights[i]->getPlaneName() << " To: " << 
            All_flights[i]->getDestAirptName() << " From: " << All_flights[i]->getOriginAirptID() << endl;
        }
        //Discover and set ID of origin airport
        temp_name = All_flights[i]->getOriginAirptName();
        tempID = findAirportID(temp_name);
        All_flights[i]->setOriginAirptID(tempID);

        if(debugging){
            cout << "DEBUGGING: Origin airport name: " << temp_name << ", Origin Airport ID" << tempID << endl;
        }

        //Discover and set ID of dest airport
        temp_name = All_flights[i]->getDestAirptName();
        tempID = findAirportID(temp_name);
        All_flights[i]->setDestAirptID(tempID);

        if(debugging){
            cout << "DEBUGGING: Dest airport name: " << temp_name << ", Dest Airport ID" << tempID << endl;
        }

        //Discover and set ID of plane
        temp_name = All_flights[i]->getPlaneName();
        tempID = findPlaneID(temp_name);
        All_flights[i]->setPlaneID(tempID);
    }
    
}

void Airline::onTimeUpdate(Clock& new_time) {

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    //Report time update to cout
    Objects_clock = new_time;
    cout << "Airport " << Airline_name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;

    //Say that we are do3ne
    TimeObserver::setIsDone();
}
