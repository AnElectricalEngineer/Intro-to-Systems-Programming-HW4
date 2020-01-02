#ifndef THEATER_H
#define THEATER_H
#include "Mat.H"

class Theater:public Mat {
public:
    Theater(int rows, int columns, int num);
    //~Theater();

    // Methods
    int getTheaterNum() const;
    void Reset();

private:
    int theater_num_;
};
#endif