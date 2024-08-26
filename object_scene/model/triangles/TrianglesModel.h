#pragma once

#include "VolumeModelImpl.h"
#include "Exceptions.h"


class TrianglesModel : public VolumeModelImpl
{
protected:
    std::unordered_set<psPoint3> vertices;    // множество уникальных вершин
    std::unordered_set<psTriangle> triangles;   // множество уникальных стреугольников
    Point3 center;
public:
    TrianglesModel();

    virtual bool addVertex(psPoint3 pv) noexcept;
    virtual bool addFace(std::initializer_list<psPoint3> &lst);
    virtual bool addFace(std::initializer_list<psPoint3> &&lst);
    // virtual bool addTriangle(psTriangle ptr) noexcept;
    virtual void setCenter(Point3 &c) noexcept;

    virtual std::unordered_set<psPoint3> getVertices() const noexcept;
    std::unordered_set<psTriangle> getTriangles() const noexcept;
    virtual Point3 getCenter() const noexcept;
};

std::ostream& operator<<(std::ostream &os, const TrianglesModel &model);
