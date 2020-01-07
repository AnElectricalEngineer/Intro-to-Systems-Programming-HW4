#include "Employee.H"
#include <stdlib.h>

//Constructor
Employee::Employee(char* name, int payPerHour, char** workHours) :
					name_(name), payPerHour_(payPerHour), workHours_(workHours) {}

//************************************************************************************* 
// Function name : getName
//
// Description : gets the name of the employee
//
// Parameters:  none
//
// Return value : the name of the employee
//*************************************************************************************
char* Employee::getName() const
{
	return name_;
}

//************************************************************************************* 
// Function name : getSalary
//
// Description : gets the salary of the employee
//
// Parameters:  none
//
// Return value : the salary of the employee
//*************************************************************************************
int Employee::getSalary() const
{
	return payPerHour_;
}


//************************************************************************************* 
// Function name : calcWeeklySalary
//
// Description : calculates the weekly salary of an employee
//
// Parameters:  none
//
// Return value : the weekly salary of the employee
//*************************************************************************************
int Employee::calcWeeklySalary() const
{
	int sumHour = 0;

	// get all work hours
	for (int i = 0; i < DAYS_IN_WEEK; i++)
	{
		char startWork[3], endWork[3];
		char* dayWork = workHours_[i]; 

		startWork[0] = dayWork[0];
		startWork[1] = dayWork[1];
		startWork[2] = '\0';

		endWork[0] = dayWork[3];
		endWork[1] = dayWork[4];
		endWork[2] = '\0';

		//add the work hours of the day
		sumHour += (atoi(endWork) - atoi(startWork));
	}

	return sumHour * payPerHour_;
}