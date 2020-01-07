#ifndef THEATER_H
#define THEATER_H
#include "Mat.H"

class Theater:public Mat {
public:
    Theater(int rows, int columns, int num); //Constructor

    // Methods

	//************************************************************************************* 
	// Function name : getTheaterNum
	//
	// Description : gets the number of a theater
	//
	// Parameters:  none
	//
	// Return value : the number of the theater
	//*************************************************************************************
    int getTheaterNum() const;
	//************************************************************************************* 
	// Function name : Reset
	//
	// Description : sets all elements to 0
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
    void Reset();

private:
    int theater_num_;
};
#endif