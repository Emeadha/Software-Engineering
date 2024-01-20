/*
Plane.cpp

Plane object implementation file
*/
// Plane.cpp
#include "Plane.h"
#include <iostream>

Plane::Plane(const std::string& plane_name) : name(plane_name) {}

void Plane::onTimeUpdate(const Clock& new_time) {
    current_time = new_time;
    std::cout << "Plane " << name << " updated its time to "
              << new_time.hours << ":" << new_time.minutes << ":" << new_time.seconds << std::endl;
}