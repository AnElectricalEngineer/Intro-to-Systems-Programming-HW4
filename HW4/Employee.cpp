#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee::Employee(char* name, int payPerHoure, char** workHours) :
					name_(name), payPerHoure_(payPerHoure), workHours_(workHours) {}

char* Employee::getName()
{
	return name_;
}

int Employee::getSalary()
{
	return payPerHoure_;
}

int Employee::calcWeeklySalary()
{
	int sumHoure = 0;

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
		sumHoure += (atoi(endWork) - atoi(startWork));
	}

	return sumHoure * payPerHoure_;
}
