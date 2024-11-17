#pragma once

#include "TransformAction.h"

class RotateAction : public TransformAction
{
public:
    RotateAction(float angle_grad, Point3 &&center, Axis axis);
    RotateAction(float angle_grad, Point3 &&center, Vector3 axis);
};
