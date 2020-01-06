#include "DubbedMovie.H"

DubbedMovie::DubbedMovie(char* name, int length, char* lang, int theater_num, int hebrewTheaterNum):Movie(name, length, lang, theater_num)
{
	dubbedMovie = new Movie(name, length, lang, hebrewTheaterNum);
}

DubbedMovie::~DubbedMovie()
{
	delete dubbedMovie;
}

BOOL DubbedMovie::addHebrewScreening(int day, int hebrew_screening_hour)
{
	return dubbedMovie->addScreening(day, hebrew_screening_hour);
}

int DubbedMovie::getHebrewTheaterNum() const
{
	return dubbedMovie->getTheaterNum();
}

int DubbedMovie::getNextHebrewScreening(int day, int hour) const
{
	return dubbedMovie->getNextScreening(day, hour);
}