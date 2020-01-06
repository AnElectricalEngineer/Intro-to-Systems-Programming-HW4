#ifndef DUBBED_MOVIE_
#define DUBBED_MOVIE_

#include "Movie.H"

class DubbedMovie:public Movie {
public:
	DubbedMovie(char* name, int length /*in minutes!*/, char* lang, int theater_num, int hebrewTheaterNum); //constructor
	~DubbedMovie(); //destructor

	//Methods
	BOOL addHebrewScreening(int day, int hebrew_screening_hour);
	int getHebrewTheaterNum() const;
	int getNextHebrewScreening(int day, int hour) const;

private:
	Movie* dubbedMovie;
};

#endif