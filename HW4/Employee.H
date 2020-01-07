#include "Proj.H"
// file Employee.H
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define DAYS_IN_WEEK 7

class Employee {
public:
	Employee(char* name, int payPerHoure, char** workHours); //constructor
	~Employee() {}; // probobly need to work on this

	//Methods
	char* getName();
	int getSalary();
	int calcWeeklySalary();

private:
	char* name_;
	int payPerHoure_;
	char** workHours_;
};

#endif // end of EMPLOYEE_H_
