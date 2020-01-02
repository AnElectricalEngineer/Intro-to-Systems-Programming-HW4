#include "Mat.h"
#include <stdio.h>

Mat::Mat(const int rows, const int columns)
{
	rows_ = rows;
	columns_ = columns;

	// creat a matrix of int
	matrix_ = new int*[rows_];
	for (int i = 0; i < rows_; i++)
	{
		//creat a row and set all element to 0
		matrix_[i] = new int[columns_]();
	}
}

Mat::~Mat()
{
	//delete first every row in the array
	for (int i = 0; i < rows_; i++)
	{
		delete[] matrix_[i];
	}

	delete[] matrix_;
}

int Mat::getRowsNum()
{
	return rows_;
}

int Mat::getColumnsNum()
{
	return columns_;
}

int Mat::getElement(int row, int column)
{
	// from the user point, row and column start from 1
	int i = row - 1;
	int j = column - 1;

	// input not corect
	//if (rows_ < i || columns_ < j)
	//	return -1;

	int* the_row= matrix_[i];
	return the_row[j];
}

void Mat::setElement(int row, int column, const int element)
{
	// from the user point, row and column start from 1
	int i = row - 1;
	int j = column - 1;

	int* the_row = matrix_[i];
	the_row[j] = element;
}
