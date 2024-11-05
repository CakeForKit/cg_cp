#pragma once
#include "TransformCommand.h"

class MoveModelCommand : public TransformCommand
{
protected:
    // PtrModel model;
    size_t idModel;
    double dx, dy, dz;

public:
    MoveModelCommand() = delete;
    MoveModelCommand(size_t _idModel, double _dx, double _dy, double _dz);

    virtual void execute();
};
