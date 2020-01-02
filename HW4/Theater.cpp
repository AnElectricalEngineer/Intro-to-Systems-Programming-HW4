#include "Theater.H"

Theater::Theater(int rows, int columns, int num):Mat(rows, columns), theater_num_(num){}

//Check that destructor works!
//Theater::~Theater()
//{
//	
//}

int Theater::getTheaterNum() const
{
	return theater_num_;
}

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