#include "Cashier.H"

Cashier::Cashier(char* name, int payPerHoure, char** workHours) :Employee(name, payPerHoure, workHours), ticket_profit_(0) {};

int Cashier::getTicketProfit() const
{
	return ticket_profit_;
}

int Cashier::sellTickets(Movie* movie, Theater* theater, BOOL isDub, int numOfTickets, int row, int column)
{
	// chack if theater num are ok
	if (isDub== FALSE && (movie->getTheaterNum != theater->getTheaterNum))
		return 0;
	if (isDub==TRUE && (((DubbedMovie*)movie)->getHebrewTheaterNum != theater->getTheaterNum))
		return 0;

	//*************************************************************************
	// the girls did not add this.
	//*************************************************************************
	// chack if the movie is film this week.
	BOOL valid = FALSE;
	for (int i = 1; i <= 7; i++)
	{
		//******************************************
		// doto: check if houre start from 1 or 0
		//******************************************
		if (movie->getNextScreening(i, 1) != 0)
		{
			valid = TRUE;
			break;
		}
	}
	if (valid == FALSE)
		return 0;



	// chach if we can sell them the tickets
	if (theater->getColumnsNum() < column + numOfTickets)
		return 0;
	// chack if the sit are free
	for (int i = 0; i < numOfTickets; i++)
	{
		if (theater->getElement(row, column + i) == TAKEN)
			return 0;
	}
	//if all sit are free, we can sell them
	for (int i = 0; i < numOfTickets; i++)
	{
		theater->setElement(row, column + i, TAKEN);
	}

	// add to profit
	ticket_profit_ += numOfTickets * movie->getTicketPrice();
	return numOfTickets * movie->getTicketPrice();
}
