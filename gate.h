/*
    gate.h

    Gate object header file
*/
// gate.h
#ifndef GATE_H
#define GATE_H
#include "timeObserver.h"
#include <string>

using namespace std;

class Gate : public TimeObserver {
public:

//Hey Harris, add the highligted stuff from the header!
    int Gate_ID;
    Clock Objects_clock;

    Gate(int Gate_ID);

    // Implement the TimeObserver interface
    virtual void onTimeUpdate(Clock& new_time) override;
};

#endif // GATE_H
