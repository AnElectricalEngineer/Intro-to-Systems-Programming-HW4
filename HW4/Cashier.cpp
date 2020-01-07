#include "Cashier.h"

//constructor
Cashier::Cashier(char* name, int payPerHour, char** workHours) :Employee(name, payPerHour, workHours), ticket_profit_(0) {};

//************************************************************************************* 
// Function name : getTicketProfit
//
// Description : calculates the total ticket profit
//
// Parameters:  none
//
// Return value : the total ticket profit
//*************************************************************************************
int Cashier::getTicketProfit() const
{
	return ticket_profit_;
}
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
int Cashier::sellTickets(Movie* movie, Theater* theater, BOOL isDub, int numOfTickets, int row, int column)
{
	// check if theater num are ok
	if (isDub == FALSE && (movie->getTheaterNum() != theater->getTheaterNum()))
		return 0;
	if (isDub == TRUE && (((DubbedMovie*)movie)->getHebrewTheaterNum() != theater->getTheaterNum()))
		return 0;
	if (theater->getRowsNum() < row)
		return 0;
	// check if we can sell them the tickets
	if (theater->getColumnsNum() < column + numOfTickets - 1)
		return 0;
	// check if the seats are free
	for (int i = 0; i < numOfTickets; i++)
	{
		if (theater->getElement(row, column + i) == TAKEN)
			return 0;
	}
	//if all seat are free, we can sell them
	for (int i = 0; i < numOfTickets; i++)
	{
		theater->setElement(row, column + i, TAKEN);
	}

	// add to profit
	ticket_profit_ += numOfTickets * movie->getTicketPrice();
	return numOfTickets * movie->getTicketPrice();
}