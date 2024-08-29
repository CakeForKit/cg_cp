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

    virtual bool addVertex(psPoint3 pv) noexcept override;
    virtual bool addFace(std::initializer_list<psPoint3> &lst) override;
    virtual bool addFace(std::initializer_list<psPoint3> &&lst) override;
    virtual void setCenter(Point3 &c) noexcept override;
    virtual void setCenter(Point3 &&c) noexcept override;

    virtual std::unordered_set<psPoint3> getVertices() const noexcept override;
    std::unordered_set<psTriangle> getTriangles() const noexcept;
    virtual Point3 getCenter() const noexcept override;

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const override;

    virtual std::ostream& print(std::ostream &os) const noexcept override;
};

std::ostream& operator<<(std::ostream &os, const TrianglesModel &model);
