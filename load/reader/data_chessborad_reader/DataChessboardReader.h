#pragma once

#include "Reader.h"
#include "Vector3.h"

class DataChessboardReader : public Reader
{
protected:
    double cell_width;
    bool printing = 0, dataRead = false;

public:
    DataChessboardReader(const char *fname);

    virtual void readData() override;
    double getCellWidth();
};
