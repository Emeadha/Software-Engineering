/*
airport.h

Airport object header file
*/

// airport.h
#ifndef AIRPORT_H
#define AIRPORT_H
#include "TimeObserver.h"
#include <string>

class Airport : public TimeObserver {
public:
    std::string name;
    Clock current_time;

    Airport(const std::string& airport_name);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(const Clock& new_time) override;
};

#endif // AIRPORT_H
