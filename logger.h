// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream> // Include for cin and cout
#include "clock.h"  
#include <fstream>
#include <iomanip> 
#include <fstream>


using namespace std;
class Logger {
public:

    //Constructor
    Logger();

    //Destructor
    ~Logger();

    // Methods to receive updates from planes, flights, and airports
	void logPlaneUpdate(const std::string& pid, 
        int p_status, const Clock& first_time, const Clock& second_time);//Creates plane log string, then sends to exportLogs to print to file
	void logFlightUpdate(const std::string& fid, 
        int f_status, const Clock& first_time, const Clock& second_time);//Creates flight log string, then sends to exportLogs to print to file
	void logAirportUpdate(const std::string& aid, int a_status,
        const Clock& first_time, const Clock& second_time);//Creates airport log string, then sends to exportLogs to print to file

    
	void exportLogsToFile(int switchCase);//Based on switch case, prints string to appropriate file


private:

    // Strings to hold log updates for each entity
    string plane_log;
    string flight_log;
    string airport_log;

    //Ofstream variables
    ofstream planeLogFile;
    ofstream flightLogFile;
    ofstream airportLogFile;

    //Names of files ot be printed to
    string planeFileName = "planeLog.txt";
    string flightFileName = "flightLog.txt";
    string airportFileName = "airportLog.txt";


};


#endif // LOGGER_H