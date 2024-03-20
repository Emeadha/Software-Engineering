#include "logger.h" 
#include "clock.h"  
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string> 
#include <sstream> // Included for using the clock/time

using namespace std;

Logger::Logger(){

    //Open respective files
    planeLogFile.open(planeFileName);
    airportLogFile.open(airportFileName);
    flightLogFile.open(flightFileName);
     
}

Logger::~Logger(){
    //close respective files
    planeLogFile.close();
    airportLogFile.close();
    flightLogFile.close();
}

// Log a plane update with status, delay time, and arrival time
void Logger::logPlaneUpdate(const string& pid, int p_status, const Clock& first_time = Clock(),
    const Clock& second_time = Clock()) 
{
    stringstream ss; // Initialize stringstream
    switch (p_status) 
    {
        case 1:
            // Log the plane delay with the duration
            ss << pid << " is delayed by [" << first_time << "]";
            plane_log += ss.str();
            break;
        case 2:
            // Log that the plane is boarding
            ss << pid << " is boarding passengers @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 3:
            // Log that the plane has departed
            ss << pid << " has departed @[" << first_time << "], planned arrival @[" << second_time << "]";
            break;
        case 4:
            // Log that the plane has arrived at its destination
            ss << pid << " has arrived at its destination @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 5:
            // Log that the plane is undergoing maintenance
            ss << pid << " is undergoing maintenance @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 6:
            // Log that the plane is refueling
            ss << pid << " is refueling @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 7:
            // Log that the plane has been cancelled
            plane_log += pid + " has been cancelled";
            break;
        default:
            // Log when no updates are available
            plane_log += pid + " has no updates at the moment";
            break;
    }

    //Call method to export
    exportLogsToFile(1);
}

// Log a flight update with status
void Logger::logFlightUpdate(const string& fid, int f_status, const Clock& first_time = Clock(),
    const Clock& second_time = Clock())
{
    switch (f_status) 
    {
        case 1:
            // Log that the flight is on time
            flight_log += "Flight " + fid + " is currently on time";
            break;
        case 2:
            // Log that the flight has been cancelled
            flight_log += "Flight " + fid + " has been cancelled";
            break;
        case 3:
            // Log that the flight is underway/in the air
            flight_log += "Flight " + fid + " is in the air";
            break;
        case 4:
            // Log that the flight is about to take off
            flight_log += "Flight " + fid + " is getting ready to take off";
            break;
        case 5:
            // Log that the flight has landed
            flight_log += "Flight " + fid + " has landed";
            break;
        case 6:
            // Log that the flight is delayed
            flight_log += "Flight " + fid + " is delayed";
            break; // corrected typo here
        default:
            // Log when no updates are available
            flight_log += "Flight " + fid + " has no updates at the moment";
            break;
    }
    //Call method to export
    exportLogsToFile(2);

}

// Log an airport update with status
void Logger::logAirportUpdate(const string& aid, int a_status, const Clock& first_time = Clock(),
    const Clock& second_time = Clock()) 
{
    switch (a_status) 
    {
        case 1:
            // Log that there's been a gate change at the airport
            airport_log += "Airport " + aid + " has experienced a gate change";
            break;
        default:
            // Log when no updates are available
            airport_log += "Airport " + aid + " has no updates at the moment";
            break;
    }

    //Call method to export
    exportLogsToFile(3);
}

// Export logs to a file
void Logger::exportLogsToFile(int switchCase) 
{
    // 1 = Plane
    // 2 = Flight 
    // 3 = Airport

    //Make sure opened properly
    if (planeLogFile.is_open() && airportLogFile.is_open() && flightLogFile.is_open()){

        switch (switchCase){

            case 1:
                // export plane log
                planeLogFile << "Plane Status: " << plane_log << endl;
                break;

            case 2:
                // export flight log 
                flightLogFile << "Flight Status: " << flight_log << endl;
                break;

            case 3:
                // export airport log
                airportLogFile << "Airport Status: " << airport_log << endl;
                break;

            default:
                //Defualt case
                cerr << "ERROR: Bad value passed to exportLogFile" << endl;
                break;

        }
    }
    else{
        cerr << "ERROR: FILE NOT OPENED CORRECTLY" << endl;
    }

}

