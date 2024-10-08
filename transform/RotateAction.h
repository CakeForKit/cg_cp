#pragma once

#include "TransformAction.h"

// вращение только вокур оси OY
class RotateAction : public TransformAction
{
public:
    RotateAction(float angle_grad);
};
