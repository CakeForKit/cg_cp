#pragma once

#include "Reader.h"
#include "Vector3.h"

class DataChessboardReader : public Reader
{
protected:
    double r_chess;
    double delta_r;
    bool printing = 0;

public:
    DataChessboardReader(const char *fname);

    virtual void readData() override;
    Point3 getCenterOfCell00();
};
