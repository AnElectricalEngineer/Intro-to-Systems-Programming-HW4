#ifndef MAT_H_
#define MAT_H_

class Mat {
public:
	Mat(int rows, int columns); //constructor
	~Mat(); //destructor
	 
	//Methods
	
	//************************************************************************************* 
	// Function name : getRowsNum
	//
	// Description : gets the number of rows in the matrix
	//
	// Parameters:  none
	//
	// Return value : number of rows in the matrix
	//*************************************************************************************
	int getRowsNum() const;
	//************************************************************************************* 
	// Function name : getColumnsNum
	//
	// Description : gets the number of columns in the matrix
	//
	// Parameters:  none
	//
	// Return value : number of columns in the matrix
	//*************************************************************************************
	int getColumnsNum() const;
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
	int getElement(int row, int column) const;
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
	void setElement(int row, int column, int element);

private:
	int rows_;
	int columns_;
	int** matrix_;
};

#endif