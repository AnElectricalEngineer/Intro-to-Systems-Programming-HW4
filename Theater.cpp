#include "Theater.h"
#include <stdio.h>

Theater::Theater(const int rows, const int columns, const int num):Mat(rows, columns)
{
	theater_num_ = num;
}

//*********************************
// i think the default destructor will work
//*********************************
//Theater::~Theater() : ~Mat() {}

int Theater::getTheaterNum()
{
	return theater_num_;
}

void Theater::Reset()
{
	int x = getRowsNum();
	int y = getColumnsNum();

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			// we need to shift the index (from "0 to len(x)-1" to "1 to len(x)")
			setElement(i+1, j+1, 0);
		}
	}
}
