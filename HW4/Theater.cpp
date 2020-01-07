#include "Theater.H"

//Constructor
Theater::Theater(int rows, int columns, int num):Mat(rows, columns), theater_num_(num){}

//************************************************************************************* 
// Function name : getTheaterNum
//
// Description : gets the number of a theater
//
// Parameters:  none
//
// Return value : the number of the theater
//*************************************************************************************
int Theater::getTheaterNum() const
{
	return theater_num_;
}

//************************************************************************************* 
// Function name : Reset
//
// Description : sets all elements to 0
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
void Theater::Reset()
{
	for(int i = 0; i < getRowsNum(); ++i)
	{
		for(int j = 0; j < getColumnsNum(); ++j)
		{
			setElement(i + 1, j + 1, 0);
		}
	}
}