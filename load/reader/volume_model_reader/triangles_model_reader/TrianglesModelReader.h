#pragma once

#include "VolumeModelReader.h"
#include "Triangle.h"

#include <cmath>
#define _USE_MATH_DEFINES

class TrianglesModelReader : public VolumeModelReader
{
protected:
    // const char *filename;
    // std::ifstream file;

    size_t stepOfRevolving;
    double alphaStep;

    std::vector<psPoint3> vertices;
    std::vector<std::vector<psPoint3>> triangles;
    std::vector<std::vector<psPoint3>> revolvElems;
    Point3 center;
    double sphere_rad, y0;

    bool printing = 0;

public:
    TrianglesModelReader(const char *fname, size_t _stepOfRevolving = 10);
    ~TrianglesModelReader();

    virtual void readData() override;
    virtual std::vector<std::vector<psPoint3>> getFaces() override;
    virtual Point3 getCenter() override;
    virtual double getSphereRad() override;
    virtual double getY0() override;

protected:
    void readVectex();
    void readRadVertex();
    void readTriangle();
    void readCirclesConnect();
};
