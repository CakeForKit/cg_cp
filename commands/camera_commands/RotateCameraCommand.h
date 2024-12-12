#pragma once

#include "BaseCommand.h"

class RotateCameraCommand : public BaseCommand
{
protected:
    float angle_grad;
    Axis axis;
    // Dir dir;

public:
    RotateCameraCommand() = delete;
    RotateCameraCommand(float _angle_grad, Axis _axis);
    // RotateCameraCommand(float _angle_grad, Dir _dir);

    virtual void execute();
};
