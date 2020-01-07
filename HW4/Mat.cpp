#include "Mat.H"

//Constructor
Mat::Mat(int rows, int columns):rows_(rows), columns_(columns)
{
	matrix_ = new int* [rows_];
	for(int i = 0; i < rows_; ++i)
	{
		matrix_[i] = new int[columns_]();
	}
}

//Destructor
Mat::~Mat()
{
	for(int i = 0; i< rows_; ++i)
	{
		delete[] matrix_[i];
	}
	delete[] matrix_;
}

//************************************************************************************* 
// Function name : getRowsNum
//
// Description : gets the number of rows in the matrix
//
// Parameters:  none
//
// Return value : number of rows in the matrix
//*************************************************************************************
int Mat::getRowsNum() const
{
	return rows_;
}

//************************************************************************************* 
// Function name : getColumnsNum
//
// Description : gets the number of columns in the matrix
//
// Parameters:  none
//
// Return value : number of columns in the matrix
//*************************************************************************************
int Mat::getColumnsNum() const
{
	return columns_;
}

//************************************************************************************* 
// Function name : getElement
//
// Description : gets a certain element from the matrix
//
// Parameters:  1) a row index (starts from 1)
//				2) a column index (starts from 1)
//
// Return value : the value of the element in matrix[row-1][column-1]
//*************************************************************************************
int Mat::getElement(int row, int column) const
{
	return matrix_[row - 1][column - 1];
}

//************************************************************************************* 
// Function name : setElement
//
// Description : sets an element in the matrix to a certain value
//
// Parameters:  1) a row index (starts from 1)
//				2) a column index (starts from 1)
//				3) the value to which to set the element
//
// Return value : number of rows in the matrix
//*************************************************************************************
void Mat::setElement(int row, int column, int element)
{
	matrix_[row - 1][column - 1] = element;
}