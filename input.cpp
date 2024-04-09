/*
* input.cpp
*
* Header file: input.h
*
* Read from input files for airport, plane, and flight objects
*
*/



#include "input.h"
#include <fstream>

std::mutex Input::input_lock;


Input::Input()
{
	//Mutex lock
	//lock_guard<mutex> lock(input_lock);

    read_airports(); // Calls to read in input for airports, planes, and flights
	sleep(1);
    read_planes();
	sleep(1);
    read_flights();
	sleep(1);
}
void Input::read_airports()
{
    //Mutex lock
	lock_guard<mutex> lock(input_lock);

    string default_file = "airportinput.csv"; //Create a default file name to look for before prompting the user for a file.
    string user_input_file; //Used in case of not finding the default file.
    int line_count;
	string line;


    //Variable being read in
    string airport_name; 
	double longitude, latitude;
	
    //Attempt to open the default file
    ifstream infile(default_file);

    //If it opens, read in from default.
    if(infile.is_open())
    {
        cout << "Default file '" << default_file << "' found. Processing input." << endl;
	}

    	//If the default file is not found, prompt the user for a file until it is found.
    else
    {
        	cout << "Default file '" << default_file << "' not found. Please insert the input file name for airport info." << endl;
			cin >> user_input_file;

		//Attempt to open file
		infile.open(user_input_file);

		//While file not found, ask until it is found.
		while(!infile.is_open())
		{
	    	cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
		    cin >> user_input_file;

		    infile.open(user_input_file);
		}
		cout << "Input file '" << user_input_file << "' found. Processing input." << endl;
		}
		//Same read in as before

		infile >> line_count;
		//cout << line_count;

		//getline to skip line_count line
		getline(infile, line);

		for(int i = 0; i < line_count; i++)
		{
			if(debugging){
				cout << "Index: " << i << endl;
			}
			//getline for airport_name since it's the only variable on the line

			getline(infile, line);

			istringstream iss(line);
			char comma;

			getline(iss, airport_name, ',');
			iss >> longitude >> comma >> latitude;


			/*//Trim the last variable on each line to remove white space
			size_t end = airport_name.length();
			while(end > 0 && isspace(airport_name[end-1]))
			{
				end--;
			}
			//Reassign airport_name once it has been trimmed
			airport_name = airport_name.substr(0, end);*/

			if(debugging){
			cout << "Airport name: " << airport_name << ", " << longitude << ", " << latitude << endl;
			}
			
	    	Airport* airport = new Airport(i, airport_name, longitude, latitude);
		   	register_airport(airport);
		   
		}
		
	cout << "Airport processing complete." << endl;

}
void Input::register_airport(Airport* airport)
{
	if(debugging){
		cout << "Registering Airport"  << endl;
	}
    //Add the parameter airport as an observer then push it onto the vector	 
    All_airports.push_back(airport);
}
void Input::read_planes()
{
	//Mutex lock
	lock_guard<mutex> lock(input_lock);

    //Same process, just with plane variables and input file instead.
    string default_file = "planeinput.csv";
    string user_input_file;
    int line_count;
	string line;

	//plane variables
	string plane_name;
    string plane_model;
    int max_passengers;
    double max_fuel;
    double burn_rate;
    double max_speed;

    ifstream infile(default_file);
	//search if the default file exists
    if(infile.is_open())
    {
        cout << "Default file '" << default_file << "' found. Processing input." << endl;
    }
    else
    {
		cout << "Default file '" << default_file << "' not found. Please insert the input file name for plane info." << endl;
		cin >> user_input_file;

		//Attempt to open file
		infile.open(user_input_file);

		//While file not found, ask until it is found.
		while(!infile.is_open())
		{
	    	cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
		    cin >> user_input_file;

		    infile.open(user_input_file);
		}
		cout << "Input file '" << user_input_file << "' found. Processing input." << endl;
	}
	


		infile >> line_count;

		//getline to skip the line_count line
		getline(infile, line);


		for(int i = 0; i < line_count; i++)
		{
			if(debugging){
				cout << "Index: " << i << endl;
			}
			//get the whole line as a string
			getline(infile, line);

			istringstream iss(line);
			char comma;

			//getline for plane_name, ending at comma
			getline(iss, plane_name, ',');
			//getline for plane_model, ending at comma
			getline(iss, plane_model, ',');
			//read in other variables, skipping commas
			iss >> max_passengers >> comma >> max_fuel >> comma >> burn_rate >> comma >> max_speed;
			
			if(debugging){
			cout << "Plane data: " << plane_name << ", " << plane_model << ", " << max_passengers << ", " << max_fuel << ", " << burn_rate << ", " << max_speed << endl;
			}

	    	Plane* plane = new Plane(i, plane_name, plane_model, max_fuel, burn_rate, max_speed, max_passengers);

			// SEG FAULT WHEN PLANE HAS TIME MANAGER

	    	register_plane(plane);
	    

		}
	cout << "Plane processing complete." << endl;
}
void Input::register_plane(Plane* plane)
{
	if(debugging){
		cout << "Registering Plane" << endl;
	}
    //Same process but for planes
    All_planes.push_back(plane);
}
void Input::read_flights()
{
	//Mutex lock
	lock_guard<mutex> lock(input_lock);

    //Same process of reading in input except with flights. Not sure if this is the way to go since I was unfamiliar with the scheduleFlights function while writing this
    string default_file = "flightinput.csv";
    string user_input_file;
    int line_count;
	string line;

    ifstream infile(default_file);
	//variables for flight
    string flight_type_name;
	string flight_type_id;
    string origin;
    string dest;
    double distance;
    int takeoff_h, takeoff_m, takeoff_s;
	int takeoff_duration, in_air_duration, deboard_duration;
    int deboard_h, deboard_m, deboard_s;
    double ticket_price;
	string plane_type;

    if(infile.is_open())
    {
		//if default file opens, read that in
		cout << "Default file '" << default_file << "' found. Processing input." << endl;		
	}
    else
    {
		cout << "Default file '" << default_file << "' not found. Please insert the input file name for flight info." << endl;
		cin >> user_input_file;
		cout << user_input_file;

		infile.open(user_input_file);

		while(!infile.is_open())
		{
		    cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
		    cin >> user_input_file;

		    infile.open(user_input_file);
		}
		cout << "Input file '" << user_input_file << "' found. Processing input." << endl; 
	}
		infile >> line_count;

		//getline grabs the line_count line
		getline(infile, line);


		for(int i = 0; i < line_count; i++)
		{
			if(debugging){
			cout << "Index: " << i << endl;	
			}

			getline(infile, line);

			istringstream iss(line);

			char comma;

			iss >> ticket_price >> comma;
			getline(iss, flight_type_name, ',');
			getline(iss, flight_type_id, ',');
			getline(iss, origin, ',');
			getline(iss, dest, ',');
			
			iss >> takeoff_h >> comma >> takeoff_m >> comma >> takeoff_s >> comma >> takeoff_duration >> comma >> in_air_duration >> comma >> deboard_duration >> comma >> distance >> comma;

			getline(iss, plane_type, ',');

			iss >> deboard_h >> comma >> deboard_m >> comma >> deboard_s;

			//Trim the last variable on each line to remove white space
			/*size_t end = plane_type.length();
			while(end > 0 && isspace(plane_type[end-1]))
			{
				end--;
			}
			//Reassign plane_type once it has been trimmed
			plane_type = plane_type.substr(0, end);*/


			if(debugging){
				cout << "Flight data: " << ticket_price << ", " << origin << ", " << dest << ", " << flight_type_name << ", " << flight_type_id << ", " << origin << ", " <<  dest << ", " <<  takeoff_h << ", " << takeoff_m << ", " << takeoff_s << ", " << takeoff_duration << ", " << in_air_duration << ", " << deboard_duration << ", " << distance << ", " << plane_type << ", " << deboard_h << ", " << deboard_m << ", " << deboard_s << endl;
			}
			//cerr << "----------" << endl;
			//cerr << ticket_price << ", " << flight_type_name << ", " << plane_name << ", " << dest << ", " <<  origin << ", " <<  departure_h << ", " << departure_m << ", " << departure_s << ", " << arrival_h << ", " << arrival_m << ", " << arrival_s << ", " << distance << endl;
	
		    Flight* flight = new Flight(i, ticket_price, flight_type_name, flight_type_id, plane_type, dest, origin, takeoff_h, takeoff_m, takeoff_s, deboard_h, deboard_m, deboard_s, distance, takeoff_duration, in_air_duration, deboard_duration);
		    register_flight(flight);
	
		}
	cout << "Flight processing complete." << endl;
}
void Input::register_flight(Flight* flight)
{
	if(debugging){
		cout << "Registering Flight" << endl;
	}
    //Don't create as an observer since this is something to be scheduled.
    All_flights.push_back(flight);
}
//Return vectors to airline (probably) so they can be registered as time observers
vector<Airport*>& Input::get_airport_vector()
{
	//Mutex lock
	lock_guard<mutex> lock(input_lock);
	return All_airports;
}
vector<Plane*>& Input::get_plane_vector()
{
	//Mutex lock
	lock_guard<mutex> lock(input_lock);
	return All_planes;
}
vector<Flight*>& Input::get_flight_vector()
{
	//Mutex lock
	lock_guard<mutex> lock(input_lock);
	return All_flights;
}