// file Mat.H
#ifndef MAT_H
#define MAT_H


//*******************************
// do we need to use const for the input?
//*******************************
class Mat {
public:
    Mat(const int rows, const int columns);
    ~Mat();

    // Methods
    int getRowsNum();
    int getColumnsNum();
    int getElement(int row, int column);
    void setElement(int row, int column, const int element);

private:
    int** matrix_; // pointer to matrix
    int rows_;
    int columns_;
};
#endif
