#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

// file Employee.H

#define DAYS_IN_WEEK 7

class Employee {
public:
	Employee(char* name, int payPerHour, char** workHours); //constructor

	//Methods

	//************************************************************************************* 
	// Function name : getName
	//
	// Description : gets the name of the employee
	//
	// Parameters:  none
	//
	// Return value : the name of the employee
	//*************************************************************************************
	char* getName() const;

	//************************************************************************************* 
	// Function name : getSalary
	//
	// Description : gets the salary of the employee
	//
	// Parameters:  none
	//
	// Return value : the salary of the employee
	//*************************************************************************************
	int getSalary() const;

	//************************************************************************************* 
	// Function name : calcWeeklySalary
	//
	// Description : calculates the weekly salary of an employee
	//
	// Parameters:  none
	//
	// Return value : the weekly salary of the employee
	//*************************************************************************************
	int calcWeeklySalary() const;

private:
	char* name_;
	int payPerHour_;
	char** workHours_;
};

#endif // end of EMPLOYEE_H_