/*
Plane.h

Plane object header file
*/
// Plane.h
#ifndef PLANE_H
#define PLANE_H
#include "TimeObserver.h"
#include <string>

class Plane : public TimeObserver {
public:
    std::string name;
    Clock current_time;

    Plane(const std::string& plane_name);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(const Clock& new_time) override;
};

#endif // PLANE_H
