#ifndef MOVIE_H_
#define MOVIE_H_

#include "Proj.H"
#include "Mat.H"

#define DAYS_IN_WEEK 7

class Movie:public Mat {
public:
	Movie(char* name, int length /*in minutes!*/, char* lang, int theater_num); //constructor
	//~Movie(); //destructor

	//Methods
	char* getName() const;
	int getLength() const; //returns minutes!
	char* getLanguage() const;
	int getTheaterNum() const;
	static int getTicketPrice();
	BOOL addScreening(int day, int screening_hour);
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