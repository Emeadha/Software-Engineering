#include "logger.h"

int main() {
    // Create an instance of the Logger class
    logger::Logger my_logger;

    // Log updates for planes, flights, and airports
    my_logger.logPlaneUpdate("ABC123", 1);  // Plane ABC123 is delayed
    my_logger.logFlightUpdate("F123", 1);   // Flight # F123 is on time
    my_logger.logAirportUpdate("LAX", 1);   // Departing from LAX has experienced a gate change

    // Export logs to a file
    my_logger.exportLogsToFile("log.txt");

    return 0;
}
