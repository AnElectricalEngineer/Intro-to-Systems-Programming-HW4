// file THEATER.H
#ifndef THEATER_H
#define THEATER_H
#include "Mat.h"


//*******************************
// do we need to use const for the input?
//*******************************
class Theater :public Mat{
public:
    Theater(const int rows, const int columns, const int num);
    //*********************************
    // i think the default destructor will work
    //*********************************
    ~Theater() {};

    // Methods
    int getTheaterNum();
    void Reset();

private:
    int theater_num_;
};
#endif
