#pragma once

#include "BaseLoadCommand.h"

class TrianglesChessboardLoadCommand : public BaseLoadCommand
{
protected:
    const char *fnBlackCells, *fnWhiteCells, *fnBase;
    idMaterial id_matBlackCells, id_matWhiteCells, id_matBase;

public:
    TrianglesChessboardLoadCommand() = delete;
    TrianglesChessboardLoadCommand(const char *_fnBlackCells,
                            idMaterial _id_matBlackCells, 
                            const char *_fnWhiteCells,
                            idMaterial _id_matWhiteCells, 
                            const char *_fnBase,
                            idMaterial _id_matBase);

    virtual void execute();
};
