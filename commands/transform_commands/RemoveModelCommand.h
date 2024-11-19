#pragma once
#include "TransformCommand.h"

class RemoveModelCommand : public TransformCommand
{
public:
    RemoveModelCommand() = delete;
    RemoveModelCommand(size_t _idModel);

    virtual void execute();
};
