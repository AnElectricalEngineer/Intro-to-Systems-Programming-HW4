#ifndef MAT_H_
#define MAT_H_

class Mat {
public:
	Mat(int rows, int columns); //constructor
	~Mat(); //destructor
	 
	//Methods
	int getRowsNum() const;
	int getColumnsNum() const;
	int getElement(int row, int column) const;
	void setElement(int row, int column, int element);

private:
	int rows_;
	int columns_;
	int** matrix_;
};

#endif