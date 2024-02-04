/*
airport.h

Airport object header file
*/

// airport.h
#ifndef AIRPORT_H
#define AIRPORT_H


#include "TimeObserver.h"
#include <string>

using namespace std;   

class Airport : public TimeObserver {
public:
    string name;
    Clock Objects_clock;

    Airport(string airport_name);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // AIRPORT_H
