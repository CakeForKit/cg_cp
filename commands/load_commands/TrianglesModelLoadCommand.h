#pragma once

#include "BaseLoadCommand.h"

class TrianglesModelLoadCommand : public BaseLoadCommand
{
protected:
    const char *filename;

public:
    TrianglesModelLoadCommand() = delete;
    TrianglesModelLoadCommand(const char *_filename, idMaterial _id_material);

    virtual void execute();
};
