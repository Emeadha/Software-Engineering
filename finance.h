/*
*   finance.h
*
*   Used to create financial summaries of days, 
*   flights, and total costs and revenue.
*
*   Objects will report costs and revenue to the 
*   finance object so that finance can keep track of 
*   the overall daily/total costs and revenues.
*
*
*
*
*
*/

#ifndef FINANCE_H
#define FINANCE_H

#include "timeManager.h"
#include "plane.h"
#include "airport.h"
#include "passenger.h"
#include "airline.h"
#include "input.h"
#include "logger.h"
#include <iostream>
#include <fstream>
#include <mutex>
#include <unistd.h>

using namespace std;

class Finance {

    private:
        double totalDailyCost = 0;
        double totalDailyRevenue = 0;

        double totalOverallCost = 0;
        double totalOverallRevenue = 0;

        ofstream financeObj;

        const string financeFileName;

        

    public:
        Finance();

        double calculateRevenue(Flight flight, Plane plane);
        void reportPlaneCost(int planeID, double value);
        void reportPlaneRevenue(int planeID, double value);
        void reportDay(int day);
        void reportOverall();
};
#endif //FINANCE_H


