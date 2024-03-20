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
	void logPlaneUpdate(const std::string& pid, int p_status, const Clock& first_time, const Clock& second_time);
	void logFlightUpdate(const std::string& fid, int f_status, const Clock& first_time, const Clock& second_time);
	void logAirportUpdate(const std::string& aid, int a_status, const Clock& first_time, const Clock& second_time);
	void exportLogsToFile(int switchCase);


    // Method for manual logging updates for testing purposes
    void manualLogUpdates();

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