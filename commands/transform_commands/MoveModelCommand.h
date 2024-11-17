#pragma once
#include "TransformCommand.h"

class MoveModelCommand : public TransformCommand
{
protected:
    double dx, dy, dz;

public:
    MoveModelCommand(size_t _idModel, double _dx, double _dy, double _dz);

    virtual void execute();
};
