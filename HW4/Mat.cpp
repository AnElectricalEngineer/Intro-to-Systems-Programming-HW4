#include "Mat.H"

Mat::Mat(int rows, int columns):rows_(rows), columns_(columns)
{
	matrix_ = new int* [rows_];
	for(int i = 0; i < rows_; ++i)
	{
		matrix_[i] = new int[columns_]();
	}
}

Mat::~Mat()
{
	for(int i = 0; i< rows_; ++i)
	{
		delete[] matrix_[i];
	}
	delete[] matrix_;
}

int Mat::getRowsNum() const
{
	return rows_;
}

int Mat::getColumnsNum() const
{
	return columns_;
}

int Mat::getElement(int row, int column) const
{
	return matrix_[row - 1][column - 1];
}

void Mat::setElement(int row, int column, int element)
{
	matrix_[row - 1][column - 1] = element;
}