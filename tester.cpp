#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Mat.h"
#include "Theater.h"

int main()
{
	// test MAT
	Mat chess(10, 5);
	int row = chess.getRowsNum();
	int col = chess.getColumnsNum();
	int data = chess.getElement(7, 3);
	int a = 10;
	chess.setElement(7, 3, a);
	data = chess.getElement(7, 3);

	//test Theater
	int b = 1, c = 2, d = 3;
	Theater thea(a, b, c);
	data = thea.getElement(c, d);
	thea.setElement(d, b, c);
	data = thea.getElement(d, b);
	thea.Reset();
	data = thea.getElement(d, b);
}
