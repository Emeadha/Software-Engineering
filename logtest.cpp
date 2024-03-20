#include "logger.h"
#include "clock.h"

int main() {
    // Create an instance of the Logger
    logger::Logger myLogger;

    // Define the data
    std::string fid = "UA567";
    std::string aid = "LAX";
    std::string pid = "Boeing747";
    int plane_status = 1; // Assuming plane status 1 means delayed
    int flight_status = 6; // Assuming flight status 6 means delayed
    int airport_status = 0; // Assuming default airport status

    // Simulate logging updates
    myLogger.logPlaneUpdate(pid, plane_status, Clock(1, 30, 0), Clock()); // Assuming a delay of 1 hour and 30 minutes
    myLogger.logFlightUpdate(fid, flight_status);
    myLogger.logAirportUpdate(aid, airport_status);

    // Export logs to a file
    myLogger.exportLogsToFile("log.txt");

    return 0;
}
