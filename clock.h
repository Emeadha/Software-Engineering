/*
clock.h

Basic time formatting, will be called by other classes
*/
// Clock.h
#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

using namespace std;

class Clock {
public:

    //Three basic units - may change at later date
    int hours;
    int minutes;
    int seconds;

    // Constructor
    Clock(int h, int m, int s);

    //Overloading operators for clock (makes life a lot easier)
    //Equals operator, assigns clock on left to that of right
    Clock& operator=(const Clock otherClock){
        this->hours = otherClock.hours;
        this->minutes = otherClock.minutes;
        this->seconds = otherClock.seconds;

        return *this;
    }
    //Addition, adds value of clock on right to the left
    Clock& operator+(const Clock otherClock){
        //Check if we exceed 24 hours
        if(this->hours + otherClock.hours < 25){
            this->hours += otherClock.hours;
        }
        else{
            cerr << "Error! Clock addition exceeds 24 hours" << endl;
        }
        //If we exceed 60 min, add respective hours to hour value and keep remainder
        if(this->minutes + otherClock.minutes < 60){
            this->minutes += otherClock.minutes;
        }
        else{
            this->hours += (this->minutes + otherClock.minutes)/60;
            this->minutes = (this->minutes + otherClock.minutes)%60;
        }
        //Same idea with min but with seconds
        if(this->seconds + otherClock.seconds < 60){
            this->seconds += otherClock.seconds;
        }
        else{
            this->minutes += (this->seconds + otherClock.seconds)/60;
            this->seconds = (this->seconds + otherClock.seconds)%60;
        }

        return *this;

    }
    //Subtraction, reduces left clock by values on right
    Clock& operator-(const Clock otherClock);
};

#endif // CLOCK_H