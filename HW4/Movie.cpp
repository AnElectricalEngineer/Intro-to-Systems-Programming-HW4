#include "Movie.H"

int Movie::price = 35;

Movie::Movie(char* name, int length, char* lang, int theater_num) :
	Mat(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY), name_(name), length_(length), lang_(lang), theater_num_(theater_num), num_screenings_{0}{}

//Check that destructor works!
//Movie::~Movie()
//{
//	
//}

char* Movie::getName() const
{
	return name_;
}

int Movie::getLength() const
{
	return length_;
}

char* Movie::getLanguage() const
{
	return lang_;
}

int Movie::getTheaterNum() const
{
	return theater_num_;
}

int Movie::getTicketPrice()
{
	return price;
}

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