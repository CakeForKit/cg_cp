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

    // virtual void accept(const Visitor& visitor);
    // virtual Point GetCenter() const;
};