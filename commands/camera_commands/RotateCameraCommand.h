#pragma once

#include "BaseCommand.h"

class RotateCameraCommand : public BaseCommand
{
protected:
    float angle_grad;
    Axis axis;

public:
    RotateCameraCommand() = delete;
    RotateCameraCommand(float _angle_grad, Axis _axis);

    virtual void execute();
};
