/*
timeManager.cpp

Time manager implementation file
*/
// TimeManager.cpp
#include "timeManager.h"

TimeManager::TimeManager() : simulation_time(0, 0, 0) {}

void TimeManager::startSimulation(){
    
    int selection = -1;
    int day = 0;
    //THIS IS THE MAIN SIMULATION LOOP FOR TIME

    //Loop for the week
    for(int j = 0; j < 14; j++){

        day++;
        selection = -1;


        //Update the observers days
        for (auto observer : observers) {

            //Update time
            observer->updateDay(day);
        }

        while((selection > 8) || (selection < 0)){

            if(selection == 9){
                cout << "-----------------------------------" << endl;
                cout << "(0) No complication" << endl;
                cout << "(1) Bad weather" << endl;
                cout << "(2) Icing" << endl;
                cout << "(3) Jet stream" << endl;
            }
            cout << "------------------------------------" << endl;
            cout << "//   Locksneed Martian    //////////" << endl;
            cout << "//   Current Day in simulation : " << day << endl;
            cout << "------------------------------------" << endl;
            cout << "Enter complication selection...     " << endl;
            cout << "------------------------------------" << endl;
            cout << "Enter (9) for option listing" << endl;

            cin >> selection;

        }



    
        //Loop for one day
        //Each iteration is 10 minutes
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        for(int i = 0; i < 144; i++){
            // Hold values of hours, minutes, and seconds,
            // if minutes exceeds 60 add 1 to hours and reset minutes to 0
            minutes += 10;
            if(minutes >= 60){
                hours++;
                minutes = 0;
            }

            //Update time
            updateSimulationTime(hours, minutes, 0);

            //Basic error check
            for (auto observer : observers) {
                //Check if all objects are done
                if(observer->getIsDone() == false){
                    cerr << "ERROR: Object " << observer << " did not respond with done!" << endl;
                }

            }


        }
    }
}
void TimeManager::updateSimulationTime(int hours, int minutes, int seconds) {
    simulation_time = Clock(hours, minutes, seconds);
    cout << "--------------------------------------------------------" << endl;
    cout << "               TIME UPDATE   [" << simulation_time.hours << ":" << simulation_time.minutes << ":" << simulation_time.seconds << "]" << endl;
    cout << "--------------------------------------------------------" << endl;
    //cout << "Locksneed Martian Corp. 2024" << endl;

    //Send out update, wait to progess until all objects have updated
    notifyObservers();
}

void TimeManager::addObserver(TimeObserver* observer) {
    observers.push_back(observer);
}

void TimeManager::notifyObservers() {
    for (auto observer : observers) {

        //Update time
        observer->onTimeUpdate(simulation_time);
    }
}
