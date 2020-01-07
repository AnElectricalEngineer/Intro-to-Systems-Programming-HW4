#include "Proj.H"
#include "Employee.H"
#include "Movie.H"
#include "DubbedMovie.H"
#include "Theater.H"


#ifndef CASHIER_H_
#define CASHIER_H_

class Cashier:public Employee{
public:
	Cashier(char* name, int payPerHoure, char** workHours); //constructor
	~Cashier() {}; // added the default destroyer

	//Methods
	int getTicketProfit() const;
	int sellTickets(Movie* movie, Theater* theater, BOOL isDub, int numOfTickets, int row, int column);

private:
	int ticket_profit_;
};

#endif // end of CASHIER_H_
