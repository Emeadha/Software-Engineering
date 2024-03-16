/*
timeManager.cpp

Time manager implementation file
*/
// TimeManager.cpp
#include "timeManager.h"

TimeManager::TimeManager() : simulation_time(0, 0, 0) {}

void TimeManager::startSimulation(){
    //THIS IS THE MAIN SIMULATION LOOP FOR TIME
    //24 hours = 1440 minutes
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

        // Sleep for 1 second
        //this_thread::sleep_for(chrono::seconds(1));
/*
        //More advanced system with threads may be nessessary
        while(waitFlag == true){
            this_thread::sleep_for(chrono::seconds(1));

            for (auto observer : observers) {
            //Update time
            observer->getIsDone();
            }
        }
*/
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
