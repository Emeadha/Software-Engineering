// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream> // Include for cin and cout

namespace logger {
    using namespace std;
    class Logger {
    public:
        Logger() {}

        // Methods to receive updates from planes, flights, and airports
        void logPlaneUpdate(string& pid, int p_status);
        void logFlightUpdate(string& fid, int f_status);
        void logAirportUpdate(string& aid, int a_status);

        // Method to export logs to a file
        void exportLogsToFile(string& filename);

        // Method for manual logging updates for testing purposes
        void manualLogUpdates();

    private:
        // Strings to hold log updates for each entity
        string plane_log;
        string flight_log;
        string airport_log;
    };
}

#endif // LOGGER_H
