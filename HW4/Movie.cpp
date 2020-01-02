#include "Proj.H"
#include "Movie.H"

int Movie::price = 35;

Movie::Movie(char* name, int length,char* lang, int theater_num) :
	Mat(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY), name_(name), length_(length), lang_(lang), theater_num_(theater_num){}

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

//BOOL Movie::addScreening(int day, int screening_time)
//{
//	int numScreenings = 0;
//	for(int i = 1; i <= getColumnsNum(); ++i)
//	{
//		int currentElem = getElement(day, i);
//		if (currentElem > 0)
//			++numScreenings;
//		if (numScreenings >= MAX_SCREENINGS_PER_DAY)
//			return FALSE;
//		if (currentElem + getLength() <= screening_time)
//			continue;
//	}
//}

int Movie::getNextScreening(int day, int hour) const
{
	for(int i = 1; i <= getColumnsNum(); ++i)
	{
		if (getElement(day, i) > hour) // '>' is important (not '>=') - itai said so on forums
			return getElement(day, i);
	}
	return 0; //if we get here, there are no screenings that start at 'hour' or later
}