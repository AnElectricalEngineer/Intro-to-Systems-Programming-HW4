#ifndef DUBBED_MOVIE_
#define DUBBED_MOVIE_

#include "Movie.H"

class DubbedMovie:public Movie {
public:
	DubbedMovie(char* name, int length /*in minutes!*/, char* lang, int theater_num, int hebrewTheaterNum); //constructor
	~DubbedMovie(); //destructor

	//Methods

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
	BOOL addHebrewScreening(int day, int hebrew_screening_hour);

	//************************************************************************************* 
	// Function name : getHebrewTheaterNum
	//
	// Description : gets the number of the Hebrew theater 
	//
	// Parameters:  none
	//
	// Return value : the number of the Hebrew theater
	//*************************************************************************************
	int getHebrewTheaterNum() const;

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
	int getNextHebrewScreening(int day, int hour) const;

private:
	Movie* dubbedMovie;
};

#endif