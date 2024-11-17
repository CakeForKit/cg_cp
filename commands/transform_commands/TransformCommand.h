#pragma once

#include "BaseCommand.h"

class TransformCommand : public BaseCommand
{
protected:
    size_t idModel;

public:
    TransformCommand(size_t _idModel);
    virtual ~TransformCommand() = 0;
};
