#pragma once

#include "BaseLoadCommand.h"
#include "Chessboard.h"

class TrianglesChessboardLoadCommand : public BaseLoadCommand
{
protected:
    const char *fnBlackCells, *fnWhiteCells, *fnBase, *fnDataCellsReader;
    idMaterial id_matBlackCells, id_matWhiteCells, id_matBase;

public:
    TrianglesChessboardLoadCommand() = delete;
    TrianglesChessboardLoadCommand(const char *_fnBlackCells,
                            idMaterial _id_matBlackCells, 
                            const char *_fnWhiteCells,
                            idMaterial _id_matWhiteCells, 
                            const char *_fnBase,
                            idMaterial _id_matBase,
                            const char *_fnDataCellsReader);

    virtual void execute();
};
