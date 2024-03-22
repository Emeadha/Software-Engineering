#include <iostream>
#include <fstream>
#include "clock.h"

using namespace std;

class Logger 
{
public:
    // Constructor
    Logger();

    // Destructor
    ~Logger();

    // Methods to receive updates from planes, flights, and airports
    void logPlaneUpdate(const std::string& pid, int p_status, const Clock& first_time, const Clock& second_time);
    void logFlightUpdate(const std::string& fid, int f_status, const Clock& first_time, const Clock& second_time);
    void logAirportUpdate(const std::string& aid, int a_status, const Clock& first_time, const Clock& second_time);

private:
    // Strings to hold log updates for each entity
    string plane_log;
    string flight_log;
    string airport_log;

    // Ofstream variables
    ofstream planeLogFile;
    ofstream flightLogFile;
    ofstream airportLogFile;

    // Names of files to be printed to
    const string planeFileName;
    const string flightFileName;
    const string airportFileName;

    // Variables to track whether each type of log has been exported
    bool plane_exported;
    bool flight_exported;
    bool airport_exported;

    // Method to export logs to file based on switchCase
    void exportLogsToFile(int switchCase);

    // Pointer to Logger object used for communication
    Logger* log_object;
};
