#pragma once

#include "VolumeModelReader.h"
#include "Exceptions.h"
#include "Triangle.h"

#include <fstream>
#include <assert.h>

class TrianglesModelReader : public VolumeModelReader
{
protected:
    const char *filename;
    std::ifstream file;

    std::vector<psPoint3> vertices;
    std::vector<std::vector<psPoint3>> triangles;
    Point3 center;

public:
    TrianglesModelReader(const char *fname);
    ~TrianglesModelReader();

    virtual void open() override;
    virtual void close() override;
    virtual bool isOpen() override;

    virtual void readData() override;
    // virtual std::vector<psPoint3> getVertices() override;
    virtual std::vector<std::vector<psPoint3>> getFaces() override;
    virtual Point3 getCenter() override;

protected:
    void readVectex();
    void readTriangle();
};
