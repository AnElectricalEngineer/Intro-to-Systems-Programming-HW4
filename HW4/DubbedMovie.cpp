#include "DubbedMovie.H"

//constructor
DubbedMovie::DubbedMovie(char* name, int length, char* lang, int theater_num, int hebrewTheaterNum):Movie(name, length, lang, theater_num)
{
	dubbedMovie = new Movie(name, length, lang, hebrewTheaterNum);
}

//destructor
DubbedMovie::~DubbedMovie()
{
	delete dubbedMovie;
}

//************************************************************************************* 
// Function name : addHebrewScreening
//
// Description : adds a screening of a dubbed movie, if there are no collisions with 
//               previous movies
//
// Parameters:  1) the day on which to add the screening (between 1 and 7)
//				2) the hour at which to start the screening
//
// Return value : TRUE if the addition was successful, FALSE otherwise
//*************************************************************************************
BOOL DubbedMovie::addHebrewScreening(int day, int hebrew_screening_hour)
{
	return dubbedMovie->addScreening(day, hebrew_screening_hour);
}


//************************************************************************************* 
// Function name : getHebrewTheaterNum
//
// Description : gets the number of the Hebrew theater 
//
// Parameters:  none
//
// Return value : the number of the Hebrew theater
//*************************************************************************************
int DubbedMovie::getHebrewTheaterNum() const
{
	return dubbedMovie->getTheaterNum();
}


//************************************************************************************* 
// Function name : getNextHebrewScreening
//
// Description : gets the time of the next dubbed screening of a movie 
//
// Parameters:  1) the day of the next dubbed screening
//				2) the hour from which to display the next dubbed screening
//
// Return value : the hour of the next dubbed screening of the movie
//*************************************************************************************
int DubbedMovie::getNextHebrewScreening(int day, int hour) const
{
	return dubbedMovie->getNextScreening(day, hour);
}