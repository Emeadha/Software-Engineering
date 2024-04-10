/*
*   finance.cpp
*
*   Implementation of finance.h, used to give a financial summary
*   of each day, flight, and overall costs and revenue
*
*
*/
#include "finance.h"
#include <sstream>


Finance::Finance() : financeFileName("financeLog.txt")
{
    financeObj.open(financeFileName);

	financeObj << "-------------------------------------------------------------------------" << endl;
    financeObj << "FINANCELOG                              LOCKSNEED MARTIAN CORP" << endl;
    financeObj << "-------------------------------------------------------------------------" << endl;

}

//Report a cost of a plane to the finance object
void Finance::reportPlaneCost(int planeID, double value)
{
	if(value > 0) 
	{
		financeObj << "Plane " << planeID << " reports a cost of: " << value << endl;
		totalDailyCost += value; 
		totalOverallCost += value;
	}
	else
	{
		cerr << "Error! Negative cost not allowed. " << endl;
	}
}
//Report a revenue of a plane to the finance object
void Finance::reportPlaneRevenue(int planeID, double value)
{
	if(value > 0) 
	{
		financeObj << "Plane " << planeID << " reports a cost of: " << value << endl;
		totalDailyRevenue += value;
		totalOverallRevenue += value; 
	}
	else
	{
		cerr << "Error! Negative revenue not allowed. " << endl;
	}
}
//Write a day into the financial summary log
void Finance::reportDay(int day)
{
	financeObj << "-----------------------------------------------" << endl;
	financeObj << "Simulation Day " << day << " Financial Summary" << endl;

	financeObj << "Total Cost: $" << totalDailyCost << endl;
	financeObj << "Total Revenue: $" << totalDailyRevenue << endl;
	
	if(totalDailyCost > totalDailyRevenue) 
	{
		financeObj << "A total of $" << totalDailyCost-totalDailyRevenue << " was LOST during day " << day << "." << endl;	
	}
	else if(totalDailyRevenue > totalDailyCost)
	{
		financeObj << "A total of $" << totalDailyRevenue-totalDailyCost << " was GAINED during day " << day << "." << endl;
	}
	else if(totalDailyRevenue == totalDailyCost)
	{
		financeObj << "The daily cost and revenue were equal, resulting in a net gain of $0.00. " << endl;
	}
	else
	{
		cerr << "Unexpected error in reporting daily financial summary. Day: " << day << endl;
		financeObj << "Error getting difference in revenue and cost." << endl;
	}

	financeObj << "-----------------------------------------------" << endl;
}
//Write the overall report to the financial summary log
void Finance::reportOverall()
{
	financeObj << "-----------------------------------------------" << endl;
	financeObj << "Simulation Overall Financial Summary" << endl;

	financeObj << "Total Cost: $" << totalOverallCost << endl;
	financeObj << "Total Revenue: $" << totalOverallRevenue << endl;

	if(totalOverallCost > totalOverallRevenue) 
	{
		financeObj << "A total of $" << totalOverallCost-totalOverallRevenue << " was LOST during the simulation." << endl;	
	}
	else if(totalOverallRevenue > totalOverallCost)
	{
		financeObj << "A total of $" << totalOverallRevenue-totalOverallCost << " was GAINED during the simulation." << endl;
	}
	else if(totalOverallRevenue == totalOverallCost)
	{
		financeObj << "The daily cost and revenue were equal, resulting in a net gain of $0.00. " << endl;
	}
	else
	{
		cerr << "Unexpected error in reporting overall financial summary." << endl;
		financeObj << "Error getting difference in revenue and cost." << endl;
	}
	
	financeObj << "-----------------------------------------------" << endl;
}
