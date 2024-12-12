#pragma once

#include "Reader.h"
#include "Vector3.h"
#include <vector>

class VolumeModelReader : public Reader
{
public:
    VolumeModelReader(const char *fname);
    virtual ~VolumeModelReader() = 0;

    virtual void readData() = 0;
    virtual std::vector<std::vector<psPoint3>> getFaces() = 0;
    virtual Point3 getCenter() = 0;
    virtual double getSphereRad() = 0;
    virtual double getY0() = 0;
};
