/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "Plane.h"
#include <iostream>
using namespace std;

// hello

Plane::Plane(int Plane_ID, string plane_name, float Max_fuel, float Burn_rate, 
    float Max_velocity, int Max_passengers, float Current_velocity, 
    double Odometer) : Objects_clock(0, 0, 0), flightLog("flightLog.txt"){

    //Set the plane's attributess
    this->Plane_ID = Plane_ID;
    this->Plane_model = plane_name;
    this->Fuel_tank = Fuel_tank;
    this->Max_fuel = Max_fuel;
    this->Burn_rate = Burn_rate;
    this->Current_velocity = Current_velocity;
    this->Max_velocity = Max_velocity;
    this->Max_passengers = Max_passengers;
    this->Onboard = Onboard;
    this->Count_of_passengers = Count_of_passengers;
    this->Current_velocity = Current_velocity;
    this->Odometer = Odometer;
    this->Trip_odometer = Trip_odometer;
    this->Until_maint = Until_maint;
    this->Is_ready_for_assignment = true;
    this->Is_operable = Is_operable;
    this->Is_seats_open = Is_seats_open;
    this->Daily_cost = Daily_cost;
    this->Loan_cost = Loan_cost;
    this->Range = Range;
    this->Origin_airport_ID = Origin_airport_ID;
    this->Target_airport_ID = Target_airport_ID;
    this->Target_airport_location_distance = Target_airport_location_distance;
    this->Target_gate;

    //Start plane off by waiting on the tarmac
    this->isFlying = false;
    this->isGrounded = true;
    this->isMaintenance = false;
    this->isWaiting = true;
    this->isBoarding = false;
    this->isUnboarding = false;

    //Don't worry about this but eventually will want way to print to log
    //flightLog << "Plane " << this->Plane_ID << " created. Model: " << this->Plane_ID << endl;

}

//Destructor
Plane::~Plane(){
    //Close output file
    flightLog.close();
}
void Plane::onTimeUpdate(Clock& new_time) {
    //Getting the difference in hours, minutes, and seconds 
    int diff_hours = new_time.hours - Objects_clock.hours;
    int diff_minutes = new_time.minutes - Objects_clock.minutes;
    int diff_seconds = new_time.seconds - Objects_clock.seconds; 
    //converting and storing the time difference to be referenced. 
    double difference_minutes = diff_hours * 60.0 + diff_minutes + diff_seconds/ 60.0;

    //Start by setting done to false
    TimeObserver::setIsNotDone();


    //Update the plane's time
    Objects_clock = new_time;
    //Debugging statement
    cout << "Plane " << Plane_ID << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << endl;
    //cout << "Variables: " << Plane_model << " " << Max_fuel << " " << Burn_rate << " " << Max_passengers << " " << Current_velocity << " " << Odometer << endl;

    if(isFlying){
        //Fly for the next 10 min
        fly(difference_minutes);
    }
    else if(isGrounded){
        //See why we are grounded
        if(isWaiting){
            //Decrement time in waiting
            //NEED THIS METHOD
        }
        else if(isBoarding){
            //Board passengers
            //Wow! Full flight
            boardPassengers(Max_passengers);
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

    //Say that we are done
    TimeObserver::setIsDone();
}
void Plane::fly(double duration){
    // Decrement fuel based on flight duration, where is the duration value coming from??
        checkFuelLevel(duration); 
         
        //Decrement distance based on flight duration. Trip Odometer represents How many miles the plane has flown in its current flight.
        
        double distanceTraveled = Current_velocity * (duration / 60.0); 
        Trip_odometer -= distanceTraveled;

        // Check if the distance has hit zero
        if (Trip_odometer <= 0) {
            //Land and prepare to unboard
            landAndDock();
        }
}
void Plane::goTakeOff(){
    isFlying = true;
    cout << " the plane has taken off and is flying" << endl;

}
void Plane::goLanding(){
    isFlying = false;
    Current_velocity =0;
    cout << " the plane has landed" << endl;
}
void Plane::boardPassengers(int passengers){
    //TEMP ACTION WILL EVENTUALLY BE MORE COMPLEX
    //Hey look at that a full flight!
    Onboard = passengers;

    //For now, will immediatley take off
    goTakeOff();
}
int Plane::disembarkPassengers(){
    //TEMP ACTION WILL EVENTUALLY BE MORE COMPLEX
    Onboard = 0;
    cout << "Disembarked all passengers." << endl;
    return Onboard;
}
void Plane::inWaitingTime(){
    //This is a temp fix, but for right now plane is going to wait until 10 min before
    // takeoff then board, then fly
    //The reason for this is waiting is its base state

    if(this->Objects_clock == Departure_time){
        //Go board passengers
        isBoarding = true;
    }

    /*
    waitingTime -= duration; 
    if (waitingTime < 0) {
        waitingTime = 0; //waiting time doesn't go negative
    }
    */
}
void Plane::assignFlight(int targetAirportID, Clock arrivalTime, Clock departTime){
    //Assign our old flight target ID to be our new origin
    this->Origin_airport_ID = this->Target_airport_ID;

    //Assign values passed in 
    this->Target_airport_ID = targetAirportID;
    this->Arrival_time = arrivalTime;
    this->Departure_time = departTime;

    //Flip assigned to false
    this->Is_ready_for_assignment = false;
}


void Plane::checkFuelLevel(double duration){

    if(isFlying == true){
        cout <<"Fuel level is" << this->Fuel_tank << endl;
        
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
        fuelused = duration * (Burn_rate/60.0);
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

    return this->Target_gate;
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
    this->Target_gate = gate;
}   

void Plane::setTargetAirport(int airportID){
    this->Target_airport_ID = airportID;
}

    /* END SETTERS*/

    /* BEGIN MISCELLANEOUS FUNCTIONS */
void Plane::landAndDock()
{
    //Land the plane
    goLanding();

    isFlying = false; 
    //Prepare next step, that being unboarding
    isUnboarding = true;

}

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
