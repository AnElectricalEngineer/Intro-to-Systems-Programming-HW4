#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

// file Employee.H

#define DAYS_IN_WEEK 7

class Employee {
public:
	Employee(char* name, int payPerHour, char** workHours); //constructor
	~Employee() {}; // probably need to work on this

	//Methods
	char* getName() const;
	int getSalary() const;
	int calcWeeklySalary();

private:
	char* name_;
	int payPerHour_;
	char** workHours_;
};

#endif // end of EMPLOYEE_H_