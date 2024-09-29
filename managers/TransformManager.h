#pragma once

#include "ObjectScene.h"
#include "MoveAction.h"

class TransformManager
{
public:
    void moveModel(PtrObjectScene model, double dx, double dy, double dz);
};
