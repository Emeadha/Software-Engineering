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
    
    string default_file = "airportinput.csv"; //Create a default file name to look for before prompting the user for a file.
    string user_input_file; //Used in case of not finding the default file.
    int line_count;
	string line;


    //Variables being read in
    string airport_name; 
    //double longitude;
    //double latitude;

    //Attempt to open the default file
    ifstream infile(default_file);

    //If it opens, read in from default.
    if(infile.is_open())
    {
        cout << "Default file '" << default_file << "' found. Processing input." << endl;

		//Read in line count, then create a for loop to run that many times.
		infile >> line_count; 
		//cout << line_count << endl;

		//getline to get past the line_count line
		getline(infile, line); 

		for(int i = 0; i < line_count; i++)
		{
			//cout << i << endl;
			//getline for airport_name since it's the only variable on the line
			getline(infile, airport_name);

			//cout << airport_name << endl;

			//SEG FAULT CONCERNING CONSTRUCTOR AND REGISTER AIRPORT

			//Airport* airport = new Airport(time_manager, airport_name); //Construct airport object with new name and ?id?
		    //register_airport(airport);

	    
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
		cout << line_count;

		//getline to skip line_count line
		getline(infile, line);

		for(int i = 0; i < line_count; i++)
		{
	    	//cout << i << endl;
			//getline for airport_name since it's the only variable on the line
			getline(infile, airport_name);

			//cout << airport_name << endl;


	    	//Airport* airport = new Airport(time_manager, airport_name);
		   	//register_airport(airport);
		   
		}
		
		cout << "Airport processing complete." << endl;

    }
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

		//read in the line count
		infile >> line_count; 
		//cout << line_count << endl;

		//getline to skip line_count line
		getline(infile, line);

		for(int i = 0; i < line_count; i++)
		{
			//cout << i << endl;
	    	//get the whole line
			getline(infile, line);
			//istringstream used to splice the line
			istringstream iss(line);
			//used to grab commas since it's a .csv file
			char comma;

			//getline through istringstream allows for a delimeter that stops reading when it is found
			//in this case it will always be a comma since it's a .csv

			//NOTE: getline is only used for string and iss/infile can be used for other variable types
			getline(iss, plane_model, ',');
			//read in the rest of the variables, while skipping commas
			iss >> max_passengers >> comma >> max_fuel >> comma >> burn_rate >> comma >> max_speed;
			//cout << plane_model << ", " << max_passengers << ", " << max_fuel << ", " << burn_rate << ", " << max_speed << endl;


	    	Plane* plane = new Plane(i, plane_model, max_fuel, burn_rate, max_speed, max_passengers,0,0);

			// SEG FAULT WHEN REGISTER PLANE IS CALLED

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
			//Prompt the user for an input file since the default file was not found.
	    	cout << "Input file '" << user_input_file << "' not found. Please insert another file name." << endl;
	    	cin >> user_input_file;
	    	ifstream infile(user_input_file);
		}
		//Once found, being reading
		cout << "Input file '" << user_input_file << "' found. Processing input." << endl;

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
			//getline for plane_model, ending at comma
			getline(iss, plane_model, ',');
			//read in other variables, skipping commas
			iss >> max_passengers >> comma >> max_fuel >> comma >> burn_rate >> comma >> max_speed;
			//cout << plane_model << ", " << max_passengers << ", " << max_fuel << ", " << burn_rate << ", " << max_speed << endl;


	    	Plane* plane = new Plane(i, plane_model, max_fuel, burn_rate, max_speed, max_passengers,0,0);

			// SEG FAULT WHEN REGISTER PLANE IS CALLED

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
    string default_file = "flightinput.csv";
    string user_input_file;
    int line_count;
	string line;

    ifstream infile(default_file);
	//variables for flight
    string flight_type_id;
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
		infile >> line_count;
		//cout << line_count << endl;
		
		//getline to go past the line_count line
		getline(infile, line);

		for(int i = 0; i < line_count; i++)
		{
			//cout << i << endl;	
		
			//get full line as string
			getline(infile, line);

			istringstream iss(line);

			char comma;
			//read in ticket_price (double) and skip comma
			iss >> ticket_price >> comma;
			//cout << ticket_price << ", ";

			//begin reading in string values, ignoring commas
			getline(iss, flight_type_id, ',');
			//cout << flight_type_id << ", ";
			getline(iss, origin, ',');
			//cout << origin << ", ";
			getline(iss, dest, ',');
			//cout << dest << ", ";

			//read in all following variables, skipping commas
			iss >> departure_h >> comma >> departure_m >> comma >>departure_s >> comma >>arrival_h >> comma >>arrival_m >> comma >> arrival_s >> comma >>distance;

			//cout << ticket_price << ", " << flight_type_id << ", " << origin << ", " <<  dest << ", " <<  departure_h << ", " << departure_m << ", " << departure_s << ", " << arrival_h << ", " << arrival_m << ", " << arrival_s << ", " << distance << endl;
		    Flight* flight = new Flight(ticket_price, i, flight_type_id, dest, origin, departure_h, departure_m, departure_s, arrival_h, arrival_m, arrival_s);
	    	register_flight(flight);

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
		cout << line_count << endl;

		//getline grabs the line_count line
		getline(infile, line);


		for(int i = 0; i < line_count; i++)
		{
			cout << i << endl;	
		
			getline(infile, line);

			istringstream iss(line);

			char comma;

			iss >> ticket_price >> comma;
			//cout << ticket_price << endl;
			getline(iss, flight_type_id, ',');
			//cout << flight_type_id << endl;
			getline(iss, origin, ',');
			//cout << origin << endl;
			getline(iss, dest, ',');
			//cout << dest << endl;

			iss >> departure_h >> comma >> departure_m >> comma >>departure_s >> comma >>arrival_h >> comma >>arrival_m >> comma >> arrival_s >> comma >>distance;

			//cout << ticket_price << ", " << flight_type_id << ", " << origin << ", " <<  dest << ", " <<  departure_h << ", " << departure_m << ", " << departure_s << ", " << arrival_h << ", " << arrival_m << ", " << arrival_s << ", " << distance << endl;
	
		    Flight* flight = new Flight(ticket_price, i, flight_type_id, dest, origin, departure_h, departure_m, departure_s, arrival_h, arrival_m, arrival_s);
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
