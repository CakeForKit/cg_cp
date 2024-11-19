#pragma once
#include "TransformCommand.h"

class MoveCellModelCommand : public TransformCommand
{
protected:
    size_t i, j;

public:
    MoveCellModelCommand() = delete;
    MoveCellModelCommand(size_t _idModel, size_t _i, size_t _j);

    virtual void execute();
};
