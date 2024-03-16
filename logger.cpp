// logger.cpp
#include "logger.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace logger {

    void Logger::logPlaneUpdate(string& pid, int p_status) {
        // Determine the update message based on the status
        if (p_status == 1) {
            plane_log += pid + " is delayed,";
        } else if (p_status == 2) {
            plane_log += pid + " is boarding,";
        } else if (p_status == 3) {
            plane_log += pid + " has taken off,";
        } else {
            plane_log += pid + " has no plane status updates available,";
        }
    }

    void Logger::logFlightUpdate(string& fid, int f_status) {
        // Determine the update message based on the status
        if (f_status == 1) {
            flight_log += "flight # " + fid + " is on time,";
        } else if (f_status == 2) {
            flight_log += "flight # " + fid + " has been cancelled.";
        } else {
            flight_log += "flight # " + fid + " has no flight status updates available.";
        }
    }

    void Logger::logAirportUpdate(string& aid, int a_status) {
        // Determine the update message based on the status
        if (a_status == 1) {
            airport_log += "departing from " + aid + " has experienced a gate change,";
        } else {
            airport_log += aid + " has no airport status updates available,";
        }
    }

    void Logger::exportLogsToFile(string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Status log update:\n";
            file << plane_log << " " << airport_log << " " << flight_log << endl;
            file.close();
            cout << "Logs exported to " << filename << " successfully." << endl;;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
}
