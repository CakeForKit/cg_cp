#pragma once

#include "Model.h"
#include "Camera.h"
#include "MoveAction.h"
#include "RotateAction.h"

class TransformManager
{
public:
    void moveModel(PtrModel model, double dx, double dy, double dz);
    void rotateModel(PtrModel model, float angle);

    void moveCamera(std::shared_ptr<Camera> camera, double length, bool withChessboard = true);
    void rotateCamera(std::shared_ptr<Camera> camera, float angle, Vector3 axis);
};
