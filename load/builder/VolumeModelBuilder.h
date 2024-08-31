#pragma once

#include "VolumeModelImpl.h"
#include "VolumeModel.h"
#include "VolumeModelReader.h"

class VolumeModelBuilder
{
protected:
    std::shared_ptr<VolumeModelImpl> model { nullptr };
    std::shared_ptr<VolumeModelReader> reader { nullptr };
    // TODO material reader

    size_t part = 0;

public:
    VolumeModelBuilder(std::shared_ptr<VolumeModelReader> _reader);
    virtual ~VolumeModelBuilder() = 0;

    void readData();
    void buildFaces();
    void buildCenter();
    // void buildMaterial();

    bool isBuilt() const noexcept;

    std::shared_ptr<ObjectScene> getModel();
};