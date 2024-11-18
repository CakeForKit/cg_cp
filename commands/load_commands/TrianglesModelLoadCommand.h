#pragma once

#include "BaseLoadCommand.h"

class TrianglesModelLoadCommand : public BaseLoadCommand
{
protected:
    const char *filename;
    size_t stepOfRevolving;
    indPair indPairMaterial;
    typeChess type;

public:
    TrianglesModelLoadCommand() = delete;
    // TrianglesModelLoadCommand(const char *_filename, size_t _stepOfRevolving, idMaterial _id_material); // TODO delete
    TrianglesModelLoadCommand(const char *_filename, 
                                size_t _stepOfRevolving, 
                                indPair _indPairMaterial,
                                typeChess _type);

    virtual void execute();
};
