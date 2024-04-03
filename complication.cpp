/*
complication.cpp

Complication object implementation file
*/
#include "complication.h"

Complication::Complication(int Complication_ID, string Comp_desc, int Day_effected, int Comp_type){
    this->complication_ID = Complication_ID;
    this->comp_desc = Comp_desc;
    this->day_effected = Day_effected;
    this->comp_type = Comp_type;
}