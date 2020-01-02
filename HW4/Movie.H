#ifndef MOVIE_H_
#define MOVIE_H_
#include "Mat.H"

#define DAYS_IN_WEEK 7

class Movie:public Mat {
public:
	Movie(char* name, int length, char* lang, int theater_num); //constructor
	//~Movie(); //destructor

	//Methods
	char* getName() const;
	int getLength() const; //returns minutes!
	char* getLanguage() const;
	int getTheaterNum() const;
	static int getTicketPrice();
	//BOOL addScreening(int day, int screening_time);
	int getNextScreening(int day, int hour) const;
	
	static int price;
	
private:
	char* name_;
	int length_; //in minutes!!!
	char* lang_;
	int theater_num_;
};

#endif