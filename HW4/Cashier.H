#ifndef CASHIER_H_
#define CASHIER_H_

#include "Proj.H"
#include "Employee.h"
#include "Movie.H"
#include "DubbedMovie.H"
#include "Theater.H"

class Cashier:public Employee{
public:
	Cashier(char* name, int payPerHour, char** workHours); //constructor

	//Methods

	//************************************************************************************* 
	// Function name : getTicketProfit
	//
	// Description : calculates the total ticket profit
	//
	// Parameters:  none
	//
	// Return value : the total ticket profit
	//*************************************************************************************
	int getTicketProfit() const;

	//************************************************************************************* 
	// Function name : sellTickets
	//
	// Description : sells tickets
	//
	// Parameters:  1) the name of a movie
	//				2) the number of a theater
	//				3) if the theater is dubbed or not
	//				4) the number of tickets to be sold
	//				5) the row of the desired seats
	//				6) the rightmost column of the desired seats
	//
	// Return value : the total value of the tickets sold
	//*************************************************************************************
	int sellTickets(Movie* movie, Theater* theater, BOOL isDub, int numOfTickets, int row, int column);

private:
	int ticket_profit_;
};

#endif // end of CASHIER_H_
