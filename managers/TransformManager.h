#pragma once

#include "ObjectScene.h"
#include "MoveAction.h"
#include "RotateAction.h"

class TransformManager
{
public:
    void moveModel(PtrObjectScene model, double dx, double dy, double dz);
    void rotateModel(PtrObjectScene model, float angle);
};
