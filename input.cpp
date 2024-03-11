#include "input.h"
#include <fstream>

Input::Input(TimeManager *time_manager)
{
    read_airports(); // Calls to read in input for airports, planes, and flights
    read_planes();
    read_flights();
}
void Input::read_airports()
{
    
    string default_file = "airportinput.txt"; //Create a default file name to look for before prompting the user for a file.
    string user_input_file; //Used in case of not finding the default file.
    int line_count;

    //Variables being read in
    string airport_name; 
    double longitude;
    double latitude;

    //Attempt to open the default file
    ifstream infile(default_file);

    //If it opens, read in from default.
    if(infile.is_open())
    {
        cout << "Default file '" << default_file << "' found. Processing input." << endl;
	infile >> line_count; //Read in line count, then create a for loop to run that many times.
	for(int i = 0; i < line_count; i++)
	{
	    infile >> airport_name >> longitude >> latitude; //Read in all data.
	    //Airport* airport = new Airport(time_manager, i, airport_name, longitude, latitude); //First attempt at setting the variables, gave me allocation errors on older versions
	    //register_airport(airport);

	    //Setters for airport info.
	    airport->setAirportID(i); 
	    airport->setAirportName(airport_name);
	    //airport->setLongitude(longitude);
	    //airport->setLatitude(latitude);
	    
	    //Call for registering airport to the vector and as an observer
	    register_airport(airport);
	}
	cout << "Airport processing complete." << endl;
    }
    //If the default file is not found, prompt the user for a file until it is found.
    else
    {
        cout << "Default file '" << default_file << "' not found. Please insert the input file name for airport info." << endl;
	cin >> user_input_file;

	//Attempt to open file
	ifstream infile(user_input_file);

	//While file not found, ask until it is found.
	while(!infile.is_open())
	{
	    cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
	    cin >> user_input_file;

	    ifstream infile(user_input_file);
	}
	cout << "Input file '" << user_input_file << "' found. Processing input." << endl;

	//Same read in as before

	infile >> line_count;

	for(int i = 0; i < line_count; i++)
	{
	    infile >> airport_name >> longitude >> latitude; 
	    //Airport* airport = new Airport(time_manager, i, airport_name, longitude, latitude);
	    //register_airport(airport);
	    airport->setAirportID(i);
	    airport->setAirportName(airport_name);
	    //airport->setLongitude(longitude);
	    //airport->setLatitude(latitude);
	    register_airport(airport);
	}
	cout << "Airport processing complete." << endl;
    }
}
void Input::register_airport(Airport* airport)
{
    //Add the parameter airport as an observer then push it onto the vector	
    time_manager->addObserver(airport); 
    All_airports.push_back(airport);
}
void Input::read_planes()
{
    //Same process, just with plane variables and input file instead.
    string default_file = "planeinput.txt";
    string user_input_file;
    int line_count;

    string plane_model;
    int max_passengers;
    double max_fuel;
    double burn_rate;
    double max_speed;

    ifstream infile(default_file);

    if(infile.is_open())
    {
        cout << "Default file '" << default_file << "' found. Processing input." << endl;
	infile >> line_count;
	for(int i = 0; i < line_count; i++)
	{
	    infile >> plane_model >> max_passengers >> max_fuel >> burn_rate >> max_speed;
	    //Plane* plane = new Plane(i, plane_model, max_fuel, burn_rate, max_speed, max_passengers);
	    //register_plane(plane);
	    
	    //Need setters for these variables
	    //plane->setPlaneID(i);
	    //plane->setPlaneModel(plane_model);
	    //plane->setMaxFuel(max_fuel);
	    //plane->setBurnRate(burn_rate);
	    //plane->setMaxSpeed(max_speed);
	    //plane->setMaxPassengers(max_passengers);
	    //register_plane(plane);
	}
	cout << "Plane processing complete." << endl;
    }
    else
    {
	cout << "Default file '" << default_file << "' not found. Please insert the input file name for plane info." << endl;
	cin >> user_input_file;

	ifstream infile(user_input_file);

	while(!infile.is_open())
	{
	    cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
	    cin >> user_input_file;
	    ifstream infile(user_input_file);
	}
	cout << "Input file '" << user_input_file << "' found. Processing input." << endl;

	infile >> line_count;

	for(int i = 0; i < line_count; i++)
	{
	    infile >> plane_model >> max_passengers >> max_fuel >> burn_rate >> max_speed;
	    //Plane* plane = new Plane(i, plane_model, max_fuel, burn_rate, max_speed, max_passengers);
	    //register_plane(plane);

	    //plane->setPlaneID(i);
	    //plane->setPlaneModel(plane_model);
	    //plane->setMaxFuel(max_fuel);
	    //plane->setBurnRate(burn_rate);
	    //plane->setMaxSpeed(max_speed);
	    //plane->setMaxPassengers(max_passengers);
	    //register_plane(plane);
	}
	cout << "Plane processing complete." << endl;
    }
}
void Input::register_plane(Plane* plane)
{
    //Same process but for planes
    time_manager->addObserver(plane);
    All_planes.push_back(plane);
}
void Input::read_flights()
{
    //Same process of reading in input except with flights. Not sure if this is the way to go since I was unfamiliar with the scheduleFlights function while writing this
    string default_file = "flightinput.txt";
    string user_input_file;
    int line_count;

    ifstream infile(default_file);

    string flight_type_id;
    string origin;
    string dest;
    double total_time;
    double distance;
    int departure_time;
    int arrival_time;
    double ticket_price;

    if(infile.is_open())
    {
	cout << "Default file '" << default_file << "' found. Processing input." << endl;
	infile >> line_count;

	for(int i = 0; i < line_count; i++)
	{
	    infile >> flight_type_id >> origin >> dest >> total_time >> distance >> departure_time >> arrival_time >> ticket_price;
	    //Flight* flight = new Flight(i, dest, origin, departure_time, arrival_time, ticket_price);
	    //register_flight(flight);
	    
	    //flight->setFlightID(flight_type_id);
	    //flight->setOrigin(origin);
	    //flight->setDestination(dest);
	    //flight->setTotalTime(total_time);
	    //flight->setDistance(distance);
	    //flight->setDepartureTime(departure_time); //Need to change departure and arrival time to clock objects and pass in hour, minute, and second separately.
	    //flight->setArrivalTime(arrival_time);
	    //flight->setTicketPrice(ticket_price);
	    //register_flight(flight);
	}
	cout << "Flight processing complete." << endl;
    }
    else
    {
	cout << "Default file '" << default_file << "' not found. Please insert the input file name for flight info." << endl;
	cin >> user_input_file;

	ifstream infile(user_input_file);

	while(!infile.is_open())
	{
	    cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
	    cin >> user_input_file;

	    ifstream infile(user_input_file);
	}
	cout << "Input file '" << user_input_file << "' found. Processing input." << endl; 

	infile >> line_count;

	for(int i = 0; i < line_count; i++)
	{
	    infile >> flight_type_id >> origin >> dest >> total_time >> distance >> departure_time >> arrival_time >> ticket_price;
	    //Flight* flight = new Flight(i, dest, origin, departure_time, arrival_time, ticket_price);
	    //register_flight(flight);
	    //flight->setFlightID(flight_type_id);
	    //flight->setOrigin(origin);
	    //flight->setDestination(dest);
	    //flight->setTotalTime(total_time);
	    //flight->setDistance(distance);
	    //flight->setDepartureTime(departure_time);
	    //flight->setArrivalTime(arrival_time);
	    //flight->setTicketPrice(ticket_price);
            register_flight(flight);
	}
	cout << "Flight processing complete." << endl;
    }
}
void Input::register_flight(Flight* flight)
{
    //Don't create as an observer since this is something to be scheduled.
    All_flights.push_back(flight);
}
