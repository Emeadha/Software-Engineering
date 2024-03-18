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

Input::Input()
{
    read_airports(); // Calls to read in input for airports, planes, and flights
    read_planes();
    read_flights();
}
void Input::read_airports()
{
    
    string default_file = "airportinput.csv"; //Create a default file name to look for before prompting the user for a file.
    string user_input_file; //Used in case of not finding the default file.
    int line_count;
	string line;


    //Variable being read in
    string airport_name; 
	
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
	    	//cout << i << endl;
			//getline for airport_name since it's the only variable on the line
			getline(infile, airport_name);

			//cout << airport_name << endl;

			
	    	Airport* airport = new Airport(airport_name);
		   	register_airport(airport);
		   
		}
		
	cout << "Airport processing complete." << endl;

}
void Input::register_airport(Airport* airport)
{
    //Add the parameter airport as an observer then push it onto the vector	 
    All_airports.push_back(airport);
}
void Input::read_planes()
{
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

		//cout << line_count << endl;
		//getline to skip the line_count line
		getline(infile, line);


		for(int i = 0; i < line_count; i++)
		{
			//cout << i << endl;
	    	
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
			//cout << plane_name << ", " << plane_model << ", " << max_passengers << ", " << max_fuel << ", " << burn_rate << ", " << max_speed << endl;


	    	Plane* plane = new Plane(i, plane_name, plane_model, max_fuel, burn_rate, max_speed, max_passengers);

			// SEG FAULT WHEN PLANE HAS TIME MANAGER

	    	register_plane(plane);
	    

		}
	cout << "Plane processing complete." << endl;
}
void Input::register_plane(Plane* plane)
{
    //Same process but for planes
    All_planes.push_back(plane);
}
void Input::read_flights()
{
    //Same process of reading in input except with flights. Not sure if this is the way to go since I was unfamiliar with the scheduleFlights function while writing this
    string default_file = "flightinput.csv";
    string user_input_file;
    int line_count;
	string line;

    ifstream infile(default_file);
	//variables for flight
    string flight_type_name;
    string origin;
    string dest;
    double distance;
    int departure_h, departure_m, departure_s;
    int arrival_h, arrival_m, arrival_s;
    double ticket_price;

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
		//cout << line_count << endl;

		//getline grabs the line_count line
		getline(infile, line);


		for(int i = 0; i < line_count; i++)
		{
			//cout << i << endl;	
		
			getline(infile, line);

			istringstream iss(line);

			char comma;

			iss >> ticket_price >> comma;
			//cout << ticket_price << endl;
			getline(iss, flight_type_name, ',');
			//cout << flight_type_name << endl;
			getline(iss, origin, ',');
			//cout << origin << endl;
			getline(iss, dest, ',');
			//cout << dest << endl;

			iss >> departure_h >> comma >> departure_m >> comma >>departure_s >> comma >>arrival_h >> comma >>arrival_m >> comma >> arrival_s >> comma >>distance;

			//cout << ticket_price << ", " << origin << ", " << dest << ", " << flight_type_name << ", " << origin << ", " <<  dest << ", " <<  departure_h << ", " << departure_m << ", " << departure_s << ", " << arrival_h << ", " << arrival_m << ", " << arrival_s << ", " << distance << endl;
	
		    Flight* flight = new Flight(i, ticket_price, flight_type_name, dest, origin, departure_h, departure_m, departure_s, arrival_h, arrival_m, arrival_s, distance);
		    register_flight(flight);
	
		}
	cout << "Flight processing complete." << endl;
}
void Input::register_flight(Flight* flight)
{
    //Don't create as an observer since this is something to be scheduled.
    All_flights.push_back(flight);
}
//Return vectors to airline (probably) so they can be registered as time observers
vector<Airport*>& Input::get_airport_vector()
{
	return All_airports;
}
vector<Plane*>& Input::get_plane_vector()
{
	return All_planes;
}
vector<Flight*>& Input::get_flight_vector()
{
	return All_flights;
}