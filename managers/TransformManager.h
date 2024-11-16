#pragma once

#include "Model.h"
#include "Camera.h"
#include "MoveAction.h"
#include "RotateAction.h"

class TransformManager
{
public:
    void moveModel(PtrModel model, double dx, double dy, double dz);
    void moveModel(PtrModel model, size_t i, size_t j);
    void rotateModel(PtrModel model, float angle);

    // void moveCamera(std::shared_ptr<Camera> camera, double dx, double dy, double dz)
    void rotateCamera(std::shared_ptr<Camera> camera, float angle, Axis axis);
};
