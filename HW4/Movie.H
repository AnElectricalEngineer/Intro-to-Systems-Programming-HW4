#ifndef MOVIE_H_
#define MOVIE_H_

#include "Proj.H"
#include "Mat.H"

#define DAYS_IN_WEEK 7

class Movie:public Mat {
public:
	Movie(char* name, int length /*in minutes!*/, char* lang, int theater_num); //constructor

	//Methods

	//************************************************************************************* 
	// Function name : getName
	//
	// Description : gets the name of a movie 
	//
	// Parameters:  none
	//
	// Return value : the name of the movie
	//*************************************************************************************
	char* getName() const;

	//************************************************************************************* 
	// Function name : getLength
	//
	// Description : returns the length (in minutes) of a movie 
	//
	// Parameters:  none
	//
	// Return value : the length of the movie in minutes
	//*************************************************************************************
	int getLength() const;

	//************************************************************************************* 
	// Function name : getLanguage
	//
	// Description : gets the language of a movie 
	//
	// Parameters:  none
	//
	// Return value : the language of the movie
	//*************************************************************************************
	char* getLanguage() const;

	//************************************************************************************* 
	// Function name : getTheaterNum
	//
	// Description : gets the number of the theater 
	//
	// Parameters:  none
	//
	// Return value : the number of the theater
	//*************************************************************************************
	int getTheaterNum() const;

	//************************************************************************************* 
	// Function name : getTicketPrice
	//
	// Description : gets the price of a ticket 
	//
	// Parameters:  none
	//
	// Return value : the price of a ticket
	//*************************************************************************************
	static int getTicketPrice();

	//************************************************************************************* 
	// Function name : addScreening
	//
	// Description : adds a screening of a movie, if there are no collisions with previous
	//				 movies
	//
	// Parameters:  1) the day on which to add the screening (between 1 and 7)
	//				2) the hour at which to start the screening
	//
	// Return value : TRUE if the addition was successful, FALSE otherwise
	//*************************************************************************************
	BOOL addScreening(int day, int screening_hour);

	//************************************************************************************* 
	// Function name : getNextScreening
	//
	// Description : gets the time of the next screening of a movie 
	//
	// Parameters:  1) the day of the next screening
	//				2) the hour from which to display the next screening
	//
	// Return value : the hour of the next screening of the movie
	//*************************************************************************************
	int getNextScreening(int day, int hour) const;
	
	static int price;
	
private:
	char* name_;
	int length_; //in minutes!!!
	char* lang_;
	int theater_num_;

	int num_screenings_[DAYS_IN_WEEK]; //7x1 matrix that holds the number of screenings per day (for each week)
};

#endif