#pragma once

#include <initializer_list>
#include <unordered_set>
#include "Vector3.h"
#include "Triangle.h"
#include "intersection_type.h"

class VolumeModelImpl
{
public:
    virtual ~VolumeModelImpl() = 0;
    
    virtual bool addVertex(psPoint3 pv) = 0;
    virtual bool addFace(std::initializer_list<psPoint3> &lst) = 0;
    virtual bool addFace(std::initializer_list<psPoint3> &&lst) = 0;
    virtual void setCenter(Point3 &c) noexcept = 0;
    virtual void setCenter(Point3 &&c) noexcept = 0;
    
    virtual std::unordered_set<psPoint3> getVertices() const noexcept = 0;
    virtual Point3 getCenter() const noexcept = 0;

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const = 0;

    virtual std::ostream& print(std::ostream &os) const noexcept = 0;
};

