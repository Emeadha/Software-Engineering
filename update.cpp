#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Class representing an airport object
class airport_object 
{
private:
    string airport_code;

public:
    airport_object(string code) : airport_code(code) {}

    // Getter method to retrieve the airport code
    string getAirportCode()
    {
        return airport_code;
    }
};

// Class representing a plane object
class plane_object
{
private:
    string plane_number;

public:
    plane_object(string number) : plane_number(number) {}

    // Getter method to retrieve the plane number
    string getPlaneNumber() 
    {
        return plane_number;
    }
};

// Class representing a log object
class log_object 
{
private:
    int message_code;
    string log_status;

public:
    log_object(int code, string status) : message_code(code), log_status(status) {}

    // Getter methods to retrieve the message code and log status
    int getMessageCode() 
    {
        return message_code;
    }

    string getStatus() 
    {
        return log_status;
    }
};

// Class representing an update
class update 
{
private:
    // Vectors to store airport, plane, and log objects
    vector<airport_object> airports;
    vector<plane_object> planes;
    vector<log_object> logs;

    // Maps to store predefined messages for airports, plane numbers, and log updates
    map<int, string> airport_logs;
    map<int, string> plane_number_logs;
    map<int, string> update_logs;

public:
    // Constructor to initialize the simulator and predefined messages
    update();

    // Methods to initialize predefined messages for airports, plane numbers, and log updates
    void initialize_airport_messages();
    void initialize_plane_messages();
    void initialize_log_messages();

    // Methods to process airport, plane, and log information
    void processAirport(int code);
    void processPlane(int number);
    void processLog(int message_code, string log_status);

    // Method to print updates based on processed information
    void printUpdate();
};

// Constructor implementation for update
update::update() 
{
    initialize_airport_messages();
    initialize_plane_messages();
    initialize_log_messages();
}

// Method to initialize predefined messages for airports
void update::initialize_airport_messages() 
{
    // Populate airport_logs with predefined airport codes
    airport_logs[1] = "ATL";
    airport_logs[2] = "DFW";
    airport_logs[3] = "DEN";
    airport_logs[4] = "ORD";
    airport_logs[5] = "LAX";
    airport_logs[6] = "JFK";
    airport_logs[7] = "LAS";
    airport_logs[8] = "MCO";
    airport_logs[9] = "MIA";
    airport_logs[10] = "CLT";
    airport_logs[11] = "SEA";
    airport_logs[12] = "PHX";
    airport_logs[13] = "EWR";
    airport_logs[14] = "SFO";
    airport_logs[15] = "IAH";
    airport_logs[16] = "BOS";
    airport_logs[17] = "FLL";
    airport_logs[18] = "MSP";
    airport_logs[19] = "LGA";
    airport_logs[20] = "DTW";
    airport_logs[21] = "PHL";
    airport_logs[22] = "SLC";
    airport_logs[23] = "DCA";
    airport_logs[24] = "SAN";
    airport_logs[25] = "BWI";
    airport_logs[26] = "TPA";
    airport_logs[27] = "AUS";
    airport_logs[28] = "IAD";
    airport_logs[29] = "BNA";
    airport_logs[30] = "MDW";
    airport_logs[31] = "PARIS";
}

// Method to initialize predefined messages for plane numbers
void update::initialize_plane_messages() 
{
    // Populate plane_number_logs with predefined plane numbers
    plane_number_logs[101] = "B600-1";
    plane_number_logs[102] = "B600-2";
    plane_number_logs[103] = "B600-3";
    plane_number_logs[104] = "B600-4";
    plane_number_logs[105] = "B600-5";
    plane_number_logs[106] = "B600-6";
    plane_number_logs[107] = "B600-7";
    plane_number_logs[108] = "B600-8";
    plane_number_logs[109] = "B600-9";
    plane_number_logs[110] = "B600-10";
    plane_number_logs[111] = "B600-11";
    plane_number_logs[112] = "B600-12";
    plane_number_logs[113] = "B600-13";
    plane_number_logs[114] = "B600-14";
    plane_number_logs[115] = "B600-15";
    plane_number_logs[116] = "B800-16";
    plane_number_logs[117] = "B800-17";
    plane_number_logs[118] = "B800-18";
    plane_number_logs[119] = "B800-19";
    plane_number_logs[120] = "B800-20";
    plane_number_logs[121] = "B800-21";
    plane_number_logs[122] = "B800-22";
    plane_number_logs[123] = "B800-23";
    plane_number_logs[124] = "B800-24";
    plane_number_logs[125] = "B800-25";
    plane_number_logs[126] = "B800-26";
    plane_number_logs[127] = "B800-27";
    plane_number_logs[128] = "B800-28";
    plane_number_logs[129] = "B800-29";
    plane_number_logs[130] = "B800-30";
    plane_number_logs[131] = "A100-31";
    plane_number_logs[132] = "A100-32";
    plane_number_logs[133] = "A100-33";
    plane_number_logs[134] = "A100-34";
    plane_number_logs[135] = "A100-35";
    plane_number_logs[136] = "A100-36";
    plane_number_logs[137] = "A100-37";
    plane_number_logs[138] = "A100-38";
    plane_number_logs[139] = "A100-39";
    plane_number_logs[140] = "A100-40";
    plane_number_logs[141] = "A100-41";
    plane_number_logs[142] = "A100-42";
    plane_number_logs[143] = "A300-43";
    plane_number_logs[144] = "A300-44";
    plane_number_logs[145] = "A300-45";
    plane_number_logs[146] = "A300-46";
    plane_number_logs[147] = "A300-47";
    plane_number_logs[148] = "A300-48";
    plane_number_logs[149] = "A300-49";
    plane_number_logs[150] = "A300-50";
    plane_number_logs[151] = "A300-51";
    plane_number_logs[152] = "A300-52";
    plane_number_logs[153] = "A300-53";
    plane_number_logs[154] = "A300-54";
    plane_number_logs[155] = "A300-55";
}

// Method to initialize predefined messages for log updates
void update::initialize_log_messages() 
{
    // Populate update_logs with predefined log messages
    update_logs[1001] = "on time";
    update_logs[1002] = "boarding";
    update_logs[1003] = "delayed";
    update_logs[1004] = "taxiing";
    update_logs[1005] = "departed";
    update_logs[1006] = "landing";
    update_logs[1007] = "at gate";
    update_logs[1008] = "cancelled";
    update_logs[1009] = "diverted";
    update_logs[1010] = "at another gate";
    update_logs[1011] = "undergoing maintenance";
    update_logs[1012] = "undergoing a crew change";
}

// Method to process airport information and create an airport object
void update::processAirport(int code) 
{
    // Create an airport object and add it to the airports vector
    airport_object airport(airport_logs[code]);
    airports.push_back(airport);
}

// Method to process plane information and create a plane object
void update::processPlane(int number) 
{
    // Create a plane object and add it to the planes vector
    plane_object plane(plane_number_logs[number]);
    planes.push_back(plane);
}

// Method to process log information and create a log object
void update::processLog(int message_code, string log_status) 
{
    // Create a log object and add it to the logs vector
    log_object log(message_code, log_status);
    logs.push_back(log);
}

// Method to print updates based on processed information
void update::printUpdate() 
{
    for (size_t i = 0; i < airports.size(); ++i) 
    {
        // Print the flight information using the getters of airport, plane, and log objects
        cout << "Flight #" << planes[i].getPlaneNumber() << ", departing from "
             << airports[i].getAirportCode() << " is " << update_logs[logs[i].getMessageCode()] << endl;
    }
}


int main() 
{
    // Creates an instance of the update class named simulator.
    update simulator;

    // For demonstration purposes, manually adding log entries here.
    simulator.processAirport(001);
    simulator.processPlane(101);
    simulator.processLog(1001, "boarding");

    // Print update to display the flight information based on the processed data.
    simulator.printUpdate();

    return 0;
}
