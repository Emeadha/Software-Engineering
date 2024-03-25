/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "Plane.h"
#include <iostream>
using namespace std;

// hello

Plane::Plane(int Plane_ID, string Plane_name, string Plane_model, float Max_fuel, float Burn_rate, 
    float Max_velocity, int Max_passengers) : Objects_clock(0, 0, 0){

    //Set the plane's main attributess
    this->Plane_ID = Plane_ID;
    this->Plane_name = Plane_name;
    this->Plane_model = Plane_model;

    //Set starting values
    this->Max_fuel = Max_fuel;
    this->Fuel_tank = Max_fuel;
    this->Burn_rate = Burn_rate;
    this->Max_velocity = Max_velocity;
    this->Max_passengers = Max_passengers;

    //Defualt values
    this->Current_velocity = 0;
    this->Odometer = 0;
    this->Trip_odometer = 0;
    this->Until_maint = 999999999;

    this->Is_ready_for_assignment = true;
    this->Is_operable = true;
    this->Is_seats_open = true;
    this->Daily_cost = 100;
    this->Loan_cost = 50;
    this->Range = 99999999999;

    //To be set by scheduler
    this->Target_airport_location_distance = 0;

    //Start plane off by waiting on the tarmac
    this->isFlying = false;
    this->isGrounded = true;
    this->isMaintenance = false;
    this->isWaiting = true;
    this->isBoarding = false;
    this->isUnboarding = false;


}

//Destructor
Plane::~Plane(){
}
void Plane::onTimeUpdate(Clock& new_time) {

    /*
    WHAT THIS METHOD DOES
    1. Sets its done boolean to false
    2. Updates time
    3. Calculates time change (useful for later calculations)
    4. Prints log (temporary)
    5. Makes decsion based on status by calling plane status
    6. Sets done boolean to true
    */

    //Start by setting done to false
    TimeObserver::setIsNotDone();

    //Update the plane's time
    Objects_clock = new_time;

    //Find duration of update
    this->duration=findDuration(new_time);

    //Debugging statement
    cout << "Plane " << Plane_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
    //cout << "Variables: " << Plane_model << " " << Max_fuel << " " << Burn_rate << " " << Max_passengers << " " << Current_velocity << " " << Odometer << endl;

    //Check status and make decison
    planeStatus();

    //Say we are done
    TimeObserver::setIsDone();
}
double Plane::findDuration(Clock& new_time){
    //Getting the difference in hours, minutes, and seconds 
    int diff_hours = new_time.hours - Objects_clock.hours;
    int diff_minutes = new_time.minutes - Objects_clock.minutes;
    int diff_seconds = new_time.seconds - Objects_clock.seconds; 
    //converting and storing the time difference to be referenced. 
    double duration = diff_hours * 60.0 + diff_minutes + diff_seconds/ 60.0;

    return duration;
}
void Plane::planeStatus(){
   

    if(isFlying){
        //Want to start by checking if it is flying
        fly();     
    }
    else if(isGrounded){
        //See why we are grounded
        if(isWaiting){
            //Decrement time in waiting
            inWaitingTime();
            
        }
        else if(isBoarding){
            //Board passengers
            boardPassengers();
             
        }
        else if(isUnboarding){
            //Unboard passengers
            disembarkPassengers();
            
        }
        else if(isMaintenance){
            //Decrement time left in maintenence
            doMaintenance();
        }
        else{
            cerr << "Error invalid plane state! [PLANE.CPP-LINE148] (grounded tree)" << endl;
        }
    }
    else{
        cerr << "Error! Invalid plane state! [PLANE.CPP-LINE152]" << endl;
    }

    
}


void Plane::fly(){

    // Decrement fuel based on flight duration
    checkFuelLevel(); 
     
    //Decrement distance based on flight duration. Trip Odometer represents How many miles the plane has flown in its current flight.
    double distanceTraveled = this->Current_velocity * (this->duration / 60.0); 

    //Set our odometer values
    this->Odometer += distanceTraveled;
    this->Trip_odometer += distanceTraveled;

    //Change our distance to target
    this->distanceToTarget;

    cout << "Plane " << Plane_ID <<" is flying "<< Objects_clock.hours <<":"<< Objects_clock.minutes << endl;

    // Check if the distance has hit zero
    if (this->distanceToTarget <= 0) {
        //Land and prepare to unboard
        goLanding();
    }
            
        
}
void Plane::goTakeOff(){
    
    this->isFlying = false;
    cout << "Plane " << Plane_ID<< " took off at " << this->Objects_clock << " and is flying." << endl;

    //Set is flying to ture for NEXT update 
    this->isFlying = true;

    //TEMP
    //Set velocity
    this->Current_velocity = this->Max_velocity;
    
}
void Plane::goLanding(){
    
    //int total_minutes = Objects_clock.hours * 60 + Objects_clock.minutes + duration + 10;
    //Objects_clock.hours = total_minutes / 60; // Updating the hours
    //Objects_clock.minutes = total_minutes % 60; // Updating the minutes

    this->isFlying = false;
    this->Current_velocity = 0;

    //Set unboarding for NEXT update
    this->isUnboarding = true;
    
    cout << "Plane " << Plane_ID << " landed @" << this->Objects_clock << endl;
}
void Plane::boardPassengers(){
    //TEMP ACTION WILL EVENTUALLY BE MORE COMPLEX
    //Hey look at that a full flight!

    //INSTEAD - Call the airline transferToPlane method here
    //Onboard = passengers;

    cout << "Plane " << Plane_ID << " boarded " << Onboard.size() << "passengers @"<< this->Objects_clock << endl;

    //Disable boolean
    isBoarding = false;
    
    //For now, will immediatley take off
    goTakeOff();
}
void Plane::disembarkPassengers(){
    //TEMP ACTION WILL EVENTUALLY BE MORE COMPLEX
    
    //INSTEAD CALL AIRLINE OBJECT HERE
    // Ex.
    // Airline_obj->transferToGate()
    cout << "Plane " << Plane_ID << " disembarked passengers @" << this->Objects_clock << endl;

    Trip_odometer = 0; //Resetting the trip odometer back to 0

    //Plane is waiting for next assignment
    isWaiting = true;
    Is_ready_for_assignment = true;
    isUnboarding = false;

    //Important step! We let airport know this gate is now availible
    // EVENTUALLY Airline_obj->freeGate(PlaneID)

}
void Plane::inWaitingTime(){
    //This is a temp fix, but for right now plane is going to wait until 10 min before
    // takeoff then board, then fly
    //The reason for this is waiting is its base state
    cout << "Plane " <<  Plane_ID << " is in waiting state." << endl;

    //Will transition to flying if..
    // 1. It has been assigned a upcoming flight (ready for assignment = false)
    // 2. It is time to leave (departure time check)
    if((this->Objects_clock >= Departure_time) && (this->Is_ready_for_assignment == false)){
        //Go board passengers
        isBoarding = true;
        isWaiting=false;
        
    }

    /*
    waitingTime -= duration; 
    if (waitingTime < 0) {
        waitingTime = 0; //waiting time doesn't go negative
    }
    */
}
void Plane::assignFlight(int targetAirportID, Clock arrivalTime, Clock departTime, double distance){
    //Assign our old flight target ID to be our new origin
    this->Origin_airport_ID = this->Target_airport_ID;

    //Assign values passed in 
    this->Target_airport_ID = targetAirportID;
    this->Arrival_time = arrivalTime;
    this->Departure_time = departTime;
    this->Target_airport_location_distance = distance;

    //Flip assigned to false
    this->Is_ready_for_assignment = false;
    cout << "Plane " << Plane_ID << " has been assigned a flight to: Airport " << 
        this->Target_airport_ID << ", departing @" << this->Departure_time << endl;
}


void Plane::checkFuelLevel(){

    if(isFlying == true){
        cout <<"Fuel level currently is: " << this->Fuel_tank << endl;
        
        double fuelused; 
        
        
        if(Plane_model == "B600" || Plane_model == "B800"){
        Burn_rate=3217;
        } 
        else if(Plane_model == "A100"){
        Burn_rate=2479;
        }
        else if(Plane_model == "A300"){
        Burn_rate=2600;
        }
        else{
            cout << "Plane model invalid" << endl;
        }
        fuelused = this->duration * (Burn_rate/60.0);
        this->Fuel_tank -= fuelused;
        
        if (Fuel_tank <= 0){
            Fuel_tank=0;
            cout << " Fuel Tank is empty. Refuel before takeoff" << endl;}
            else{
            cout << "Fuel used" << fuelused << endl;
            cout << " Fuel Tank Level: " << this->Fuel_tank << "liters" << endl;
            }


    }

    
}

   /* BEGIN GETTERS */

int Plane::getPlaneID(){
    return this->Plane_ID;
}
string Plane::getPlaneName(){
    return this->Plane_name;
}
double Plane::getMaintenance()
{

    return this->Until_maint;
}

double Plane::getOdometer()
{

    return this->Odometer;
}

double Plane::getTripOdometer()
{

    return this->Trip_odometer;
}

bool Plane::getIsReadyForAssignment()
{

    return this->Is_ready_for_assignment;
}

bool Plane::getIsOperable()
{

    return this->Is_operable;
}

bool Plane::getIsSeatsOpen()
{

    return this->Is_seats_open;
}

string Plane::getLocation() //TODO: This needs to return an actual location
{

    return "TEMPLATE";
}

float Plane::getFuelLevel()
{

    return this->Fuel_tank;
}

double Plane::getDailyCost()
{

    return this->Daily_cost;
}

int Plane::getTargetGate()
{

    return this->Target_gate_ID;
}

int Plane::getTargetAirport()
{

    return this->Target_airport_ID;
}

int Plane::getPassengerCount()
{

    return this->Count_of_passengers;
}
   /* END GETTERS */

   /* BEGIN SETTERS*/
void Plane::resetTripOdometer()
{
     this->Trip_odometer = 0;
}

void Plane::setFuelTank(float fuel)
{
     this->Fuel_tank = fuel;
}   

void Plane::refuelToFull()
{
     this->Fuel_tank = this->Max_fuel;
}   

void Plane::setMaintStatus(bool maintStatus)
{
    this->isMaintenance = maintStatus;
}

void Plane::setArrivalTime(Clock newTime){
    this->Arrival_time = newTime;
}

void Plane::setDepartureTime(Clock newTime){
    this->Departure_time = newTime;
}
void Plane::setIsReadyForAssignment(bool isReady){
    this->Is_ready_for_assignment = isReady;
}
void Plane::setTargetGate(int gate){
    this->Target_gate_ID = gate;
}   

void Plane::setTargetAirport(int airportID){
    this->Target_airport_ID = airportID;
}

    /* END SETTERS*/

    /* BEGIN MISCELLANEOUS FUNCTIONS */
double Plane::calcCost()
{
   return 0; //TODO: This is just here to supress compiler warning
}

void Plane::doMaintenance()
{
    //WE NEED TWO DIFFERENT METHODS FOR MAINTENCE
    //1. Sets maintence time, and sets maintence to true
    //2. Chips away at maintence time then eventually sets to false

    //If in maintenance, remove 10 minutes from the timer. If the timer hits zero, set the plane to no longer be in maintenance.
    if (untilMaintDone > 0)
    {
       untilMaintDone -= 10;
       if (untilMaintDone <= 0)
       {
          setMaintStatus(false);
       }
    }

}
void Plane::sendToMaintenance(){
     this->untilMaintDone = 2160;
     this->isMaintenance = true;
}
    /* END MISCELLANEOUS FUNCTIONS */
