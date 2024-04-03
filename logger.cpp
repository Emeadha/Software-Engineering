#include "logger.h"
#include <iostream>
#include <sstream>

using namespace std;

//constructor
Logger::Logger() : planeFileName("planeLog.txt"), flightFileName("flightLog.txt"), airportFileName("airportLog.txt"), errorFileName("errorLog.txt") 
{

    // Open respective files
    planeLogFile.open(planeFileName);
    airportLogFile.open(airportFileName);
    flightLogFile.open(flightFileName);
    errorLogFile.open(errorFileName);


    // Check if files opened successfully
    if (!planeLogFile.is_open() || !airportLogFile.is_open() || !flightLogFile.is_open()) 
    {
        cerr << "ERROR: Unable to open log files for writing." << endl;
    }

    //Write opener for all files
    planeLogFile << "PLANELOG                                 LOCKSNEED MARTIAN CORP" << endl;
    planeLogFile << "--------------------------------------------------------------" << endl;

    airportLogFile << "AIRPORTLOG                              LOCKSNEED MARTIAN CORP" << endl;
    airportLogFile << "--------------------------------------------------------------" << endl;

    flightLogFile << "FLIGHTLOG                              LOCKSNEED MARTIAN CORP" << endl;
    flightLogFile << "------------------------------------------------------------" << endl;

    errorLogFile << "ERRORLOG                              LOCKSNEED MARTIAN CORP" << endl;
    errorLogFile << "------------------------------------------------------------" << endl;

}


//destructor
Logger::~Logger() 
{
    // Close respective files
    planeLogFile.close();
    airportLogFile.close();
    flightLogFile.close();
    errorLogFile.close();
}


// File that reads methods sent by plane.cpp to determine status of the plane and export it into a text file as a log 
void Logger::logPlaneUpdate(int pid, int p_status, const Clock& first_time) {
    
    //This allows only one print out statement for the progrm at a time, it slowws things down a bit,
    // but ensures saftey in our printouts
    lock_guard<mutex> lock(log_mutex);

    
    switch (p_status)
        {
        case 1:
            //plane is delayed as well as how long it is delayed for
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is delayed by " << first_time << endl;
            break;
        case 2:
            //boarding
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is boarding passengers @" << first_time << endl;
            break;
        case 3:
            //unboarding
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is unboarding passengers @" << first_time << endl;
            break;
        case 4:
            //departed time and expected arrival
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " has departed @" << first_time << endl;
            break;
        case 5:
            //has arrived and time of arrival
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " has arrived at its destination @" << first_time << endl;
            break;
        case 6:
            //undergoing maintenance
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is undergoing maintenance @" << first_time << endl;
            break;
        case 7:
            //refueling
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is refueling @" << first_time << endl;
            break;
        case 8:
            //cancelled
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " has been cancelled" << endl;
            break;
        case 9:
            //on time
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " is currently on time" << endl;
            break;
        default:
            //no updates
            planeLogFile << "PLANE STATUS: PLaneID" << pid << " has no updates at the moment" << endl;
            break;
    }

   
}

// File that reads methods sent by flight.cpp to determine status of the flight and export it into a text file as a log 
void Logger::logFlightUpdate(int fid, int f_status, string a_name_1, string a_name_2, const Clock& first_time, const Clock& second_time) {

     //This allows only one print out statement for the progrm at a time, it slowws things down a bit,
    // but ensures saftey in our printouts
    lock_guard<mutex> lock(log_mutex);

    switch (f_status) 
    {
        case 1:
            //on time
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " is currently on time";
            break;
        case 2:
            //cancelled
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " has been cancelled";
            break;
        case 3:
            //flying
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " is in the air";
            break;
        case 4:
            //Scheduled
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " Created! Scheduled to depart from " << a_name_1 << " @" << first_time << " and arrives at " << a_name_2 << " @" << second_time << endl;
            break;
        case 5:
            //has landed
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " has landed";
            break;
        case 6:
            //delayed
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " is delayed";
            break;
        default:
            //no updates
            flightLogFile << "FLIGHT STATUS: " << "Flight " << fid << " has no updates at the moment";
            break;
    }

   
}

// File that reads methods sent by airport.cpp to determine status of the airport and export it into a text file as a log 
void Logger::logAirportUpdate(int aid, int a_status, Clock first_time = Clock())
{

    //This allows only one print out statement for the progrm at a time, it slowws things down a bit,
    // but ensures saftey in our printouts
    lock_guard<mutex> lock(log_mutex);


    switch (a_status) 
    {
        case 1:
            //gate change
            airportLogFile << "AIRPORT STATUS: " << "Airport " << aid << " has experienced a gate change" << endl;
            break;
        case 2:
            //gate change
            airportLogFile << "AIRPORT STATUS: " << "Airport " << aid << " pulse check @" << first_time << endl;
            break;
        default:
            //No updates
            airportLogFile << "AIRPORT STATUS: " << "Airport " << aid << " has no updates at the moment" << endl;
            break;
    }
    
}

void Logger::errorLog(int severity, string message) //TODO: Integrate with general logger functionality- add errorLog file and export functionality. Make abort() function actually do something.
{
    //This allows only one print out statement for the progrm at a time, it slowws things down a bit,
    // but ensures saftey in our printouts
    lock_guard<mutex> lock(log_mutex);

   errorLogFile << "ERROR: " << message << ", severity " << severity << endl;
   if (severity == 2);
   {
      error1Count++;
   }

   if (error1Count >= 5 || severity == 2)
   {
      abort();
   }
}

//exports logs/information read in to the corresponding txt file
void Logger::exportLogsToFile(int switchCase) 
{
    cerr << "LOGGER: EXPORTLOGS UPDATE CALLED" << endl;

    // Open respective files
    planeLogFile.open(planeFileName);
    airportLogFile.open(airportFileName);
    flightLogFile.open(flightFileName);

   
    //Check if open, then write
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
     // Close respective files
    planeLogFile.close();
    airportLogFile.close();
    flightLogFile.close();
}
