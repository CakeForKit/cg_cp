#pragma once

#include "BaseLoadCommand.h"

class TrianglesModelLoadCommand : public BaseLoadCommand
{
protected:
    const char *filename;

public:
    TrianglesModelLoadCommand() = delete;
    TrianglesModelLoadCommand(const char *_filename);

    virtual void execute();
};
