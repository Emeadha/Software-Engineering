/*
clock.h

Basic time formatting, will be called by other classes
*/
// Clock.h
#ifndef CLOCK_H
#define CLOCK_H

class Clock {
public:

    //Three basic units - may change at later date
    int hours;
    int minutes;
    int seconds;

    // Constructor
    Clock(int h, int m, int s);
};

#endif // CLOCK_H