#include "logger.h" 
#include "clock.h"  
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string> 

using namespace std;
namespace logger 
{

// Log a plane update with status, delay time, and arrival time
void Logger::logPlaneUpdate(const string& pid, int p_status, const Clock& delay_time, const Clock& arrival_time) 
{
    switch (p_status) 
    {
        case 1:
            // Log the plane delay with the duration
            ss << pid << " is delayed by " << delay_time.toString();
            plane_log += ss.str();
            break;
        case 2:
            // Log that the plane is boarding
            plane_log += pid + " is boarding";
            break;
        case 3:
            // Log that the plane has departed
            plane_log += pid + " has departed";
            break;
        case 4:
            // Log that the plane has arrived at its destination
            ss << pid << " has arrived at its destination at " << arrival_time.toString();
            plane_log += ss.str();
            break;
        case 5:
            // Log that the plane is undergoing maintenance
            plane_log += pid + " is undergoing maintenance";
            break;
        case 6:
            // Log that the plane is refueling
            plane_log += pid + " is refueling";
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
}

// Log a flight update with status
void Logger::logFlightUpdate(const string& fid, int f_status)
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
            flight_log += "Flight " + fid + " is delayed”;
            break;
        default:
            // Log when no updates are available
            flight_log += "Flight " + fid + " has no updates at the moment";
            break;
    }
}

// Log an airport update with status
void Logger::logAirportUpdate(const string& aid, int a_status) 
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
}

// Export logs to a file
void Logger::exportLogsToFile(const string& filename) 
{
    ofstream file(filename);
    if (file.is_open()) 
    {
        file << "Status Log Update:\n";

        // export plane log
        file << "Plane Status: " << plane_log << endl;

        // export flight log 
        file << "Flight Status: " << flight_log << endl;

        // export airport log
        file << "Airport Status: " << airport_log << endl;

        file.close();
        cout << "Logs exported to " << filename << " successfully." << endl;
    } 
    else 
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

} 
