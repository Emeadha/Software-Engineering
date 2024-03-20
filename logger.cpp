#include "logger.h"
#include <iostream>
#include <sstream>

using namespace std;

//constructor
Logger::Logger() : planeFileName("planeLog.txt"), flightFileName("flightLog.txt"), airportFileName("airportLog.txt"), plane_exported(false), flight_exported(false), airport_exported(false) 
{
    // Open respective files
    planeLogFile.open(planeFileName);
    airportLogFile.open(airportFileName);
    flightLogFile.open(flightFileName);

    // Check if files opened successfully
    if (!planeLogFile.is_open() || !airportLogFile.is_open() || !flightLogFile.is_open()) 
    {
        cerr << "ERROR: Unable to open log files for writing." << endl;
    }
}

//destructor
Logger::~Logger() 
{
    // Close respective files
    planeLogFile.close();
    airportLogFile.close();
    flightLogFile.close();
}

// File that reads methods sent by plane.cpp to determine status of the plane and export it into a text file as a log 
void Logger::logPlaneUpdate(const string& pid, int p_status, const Clock& first_time, const Clock& second_time) {
    //initialize stringstream ss so we can utilize the clocktype
    stringstream ss; 
    switch (p_status)
        {
        case 1:
            //plane is delayed as well as how long it is delayed for
            ss << pid << " is delayed by [" << first_time << "]";
            plane_log += ss.str();
            break;
        case 2:
            //boarding
            ss << pid << " is boarding passengers @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 3:
            //departed time and expected arrival
            ss << pid << " has departed @[" << first_time << "], planned arrival @[" << second_time << "]";
            break;
        case 4:
            //has arrived and time of arrival
            ss << pid << " has arrived at its destination @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 5:
            //undergoing maintenance
            ss << pid << " is undergoing maintenance @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 6:
            //refueling
            ss << pid << " is refueling @[" << first_time << "]";
            plane_log += ss.str();
            break;
        case 7:
            //cancelled
            plane_log += pid + " has been cancelled";
            break;
        case 8:
            //on time
            plane_log += pid + " is currently on time";
            break;
        default:
            //no updates
            plane_log += pid + " has no updates at the moment";
            break;
    }

    // Export logs to file if not exported before
    if (!plane_exported) 
    {
        exportLogsToFile(1);
        plane_exported = true;
    }

    // Print success statement if all logs have been exported
    if (plane_exported && flight_exported && airport_exported) 
    {
        cout << "Files have been successfully exported to airportLog.txt, flightLog.txt, and planeLog.txt" << endl;
    }
}

// File that reads methods sent by flight.cpp to determine status of the flight and export it into a text file as a log 
void Logger::logFlightUpdate(const string& fid, int f_status, const Clock& first_time, const Clock& second_time) {
    switch (f_status) 
    {
        case 1:
            //on time
            flight_log += "Flight " + fid + " is currently on time";
            break;
        case 2:
            //cancelled
            flight_log += "Flight " + fid + " has been cancelled";
            break;
        case 3:
            //flying
            flight_log += "Flight " + fid + " is in the air";
            break;
        case 4:
            //about to take off
            flight_log += "Flight " + fid + " is getting ready to take off";
            break;
        case 5:
            //has landed
            flight_log += "Flight " + fid + " has landed";
            break;
        case 6:
            //delayed
            flight_log += "Flight " + fid + " is delayed";
            break;
        default:
            //no updates
            flight_log += "Flight " + fid + " has no updates at the moment";
            break;
    }

    // Export logs to file if not exported before
    if (!flight_exported) 
    {
        exportLogsToFile(2);
        flight_exported = true;
    }

    // Print success statement if all logs have been exported
    if (plane_exported && flight_exported && airport_exported)
    {
        cout << "Files have been successfully exported to airportLog.txt, flightLog.txt, and planeLog.txt" << endl;
    }
}

// File that reads methods sent by airport.cpp to determine status of the airport and export it into a text file as a log 
void Logger::logAirportUpdate(const string& aid, int a_status, const Clock& first_time, const Clock& second_time)
{
    switch (a_status) 
    {
        case 1:
            //gate change
            airport_log += "Airport " + aid + " has experienced a gate change";
            break;
        default:
            airport_log += "Airport " + aid + " has no updates at the moment";
            break;
    }

    // Export logs to file if not exported before
    if (!airport_exported)
    {
        exportLogsToFile(3);
        airport_exported = true;
    }

    // Print success statement if all logs have been exported
    if (plane_exported && flight_exported && airport_exported) 
    {
        cout << "Files have been successfully exported to airportLog.txt, flightLog.txt, and planeLog.txt" << endl;
    }
}

//exports logs/information read in to the corresponding txt file
void Logger::exportLogsToFile(int switchCase) 
{
    if (planeLogFile.is_open() && airportLogFile.is_open() && flightLogFile.is_open()) 
    {
        switch (switchCase) 
        {
            case 1:
                planeLogFile << "PLANE STATUS: " << plane_log << endl;
                break;
            case 2:
                flightLogFile << "FLIGHT STATUS: " << flight_log << endl;
                break;
            case 3:
                airportLogFile << "AIRPORT STATUS: " << airport_log << endl;
                break;
            default:
                cerr << "ERROR: Bad value passed to exportLogFile" << endl;
                break;
        }
    } 
    else 
    {
        cerr << "ERROR: FILE NOT OPENED CORRECTLY" << endl;
    }
}
