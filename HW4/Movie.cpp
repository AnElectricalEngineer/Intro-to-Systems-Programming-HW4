#include "Movie.H"

int Movie::price = 35;

Movie::Movie(char* name, int length, char* lang, int theater_num) :
	Mat(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY), name_(name), length_(length), lang_(lang), theater_num_(theater_num), num_screenings_{0}{}

//************************************************************************************* 
// Function name : getName
//
// Description : gets the name of a movie 
//
// Parameters:  none
//
// Return value : the name of the movie
//*************************************************************************************
char* Movie::getName() const
{
	return name_;
}

//************************************************************************************* 
// Function name : getLength
//
// Description : returns the length (in minutes) of a movie 
//
// Parameters:  none
//
// Return value : the length of the movie in minutes
//*************************************************************************************
int Movie::getLength() const
{
	return length_;
}

//************************************************************************************* 
// Function name : getLanguage
//
// Description : gets the language of a movie 
//
// Parameters:  none
//
// Return value : the language of the movie
//*************************************************************************************
char* Movie::getLanguage() const
{
	return lang_;
}

//************************************************************************************* 
// Function name : getTheaterNum
//
// Description : gets the number of the theater 
//
// Parameters:  none
//
// Return value : the number of the theater
//*************************************************************************************
int Movie::getTheaterNum() const
{
	return theater_num_;
}

//************************************************************************************* 
// Function name : getTicketPrice
//
// Description : gets the price of a ticket 
//
// Parameters:  none
//
// Return value : the price of a ticket
//*************************************************************************************
int Movie::getTicketPrice()
{
	return price;
}

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
BOOL Movie::addScreening(int day, int screening_hour)
{
	if (num_screenings_[day - 1] >= MAX_SCREENINGS_PER_DAY)
		return FALSE;
	//If we get here, there are LESS THAN MAX number of screenings for day
	if(num_screenings_[day - 1] == 0) //if there are no screenings at all for this particular day
	{
		setElement(day, 1, screening_hour); //set the first screening time of the day
		++num_screenings_[day - 1];
		return TRUE;
	}
	//If we get here, there is at least one screening already set for this day
	int numHours = getLength() / 60;
	/*int extraHour = 0;
	if (getLength() % 60)
		extraHour = 1;
	const int totalScreeningHours = numHours + extraHour;*/
	const int totalScreeningHours = numHours;
	int screeningIndx = 1; // for searching where to place next screening
	while(getElement(day, screeningIndx)) //while there are already screenings 
	{
		++screeningIndx;
	}
	//Here screeningIndx holds the column index (starting from 1!) of the first empty screening
	int lastScreeningTime = getElement(day, screeningIndx - 1);
	if(lastScreeningTime + totalScreeningHours < screening_hour) //If there is no collision with previous movie
	{
		setElement(day, screeningIndx, screening_hour);
		++num_screenings_[day - 1];
		return TRUE;
	}
	return FALSE; //if we get here, there was a collision between the movie to be entered and the previous movie
}

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
int Movie::getNextScreening(int day, int hour) const
{
	if (num_screenings_[day - 1] == 0)
		return 0;
	for(int i = 1; i <= getColumnsNum(); ++i)
	{
		if (getElement(day, i) > hour) // '>' is important (not '>=') - itai said so on forums
			return getElement(day, i);
	}
	return 0; //if we get here, there are no screenings that start at 'hour' or later
}