#ifndef _MAT_H_
#define _MAT_H_

class Mat {
public:
	Mat(int rows, int columns); //constructor
	~Mat(); //destructor
	int getRowsNum() const;
	int getColumnsNum() const;
	int getElement() const;
	void setElement(int element);

protected:
	int Rows;
	int Columns;
	int** matrix;
};

#endif