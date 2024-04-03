/*
complication.h

Complication object header file

*/

// complication.h
#ifndef COMPLICATION_H
#define COMPLICATION_H

#include "clock.h"

#include <string>
#include <iostream>

using namespace std;

class Complication{
    public:

        //Variables to keep track of complication info
        int complication_ID = -1;
        //int day_effected = -1;
        int comp_type = -1;

        //Constructor
        Complication(int Complication_ID, int Comp_type);

};

#endif //COMPLICATION_H
