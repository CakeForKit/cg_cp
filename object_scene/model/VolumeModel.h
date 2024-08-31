#pragma once

#include <memory.h>

#include "BaseModel.h"
#include "VolumeModelImpl.h"

class VolumeModel: public Model
{
protected:
    std::shared_ptr<VolumeModelImpl> impl;

public:
    explicit VolumeModel(std::shared_ptr<VolumeModelImpl> _impl);

    // bool addVertex(psPoint3 pv);
    // bool addFace(std::initializer_list<psPoint3> &lst);
    // bool addFace(std::initializer_list<psPoint3> &&lst);
    // void setCenter(Point3 &c);
    
    container_vertices getVertices() const noexcept;
    Point3 getCenter() const noexcept;

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const override;

    virtual std::ostream& print(std::ostream &os) const noexcept  override;
};