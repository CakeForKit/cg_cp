#pragma once

#include "BaseLoadCommand.h"

class TrianglesModelLoadCommand : public BaseLoadCommand
{
protected:
    const char *filename;
    size_t stepOfRevolving;
    indPair indPairMaterial;
    typeChess type;
    size_t pi, pj;

public:
    TrianglesModelLoadCommand() = delete;
    TrianglesModelLoadCommand(const char *_filename, 
                                size_t _stepOfRevolving, 
                                indPair _indPairMaterial,
                                typeChess _type,
                                size_t _i, size_t _j);

    virtual void execute();
};
