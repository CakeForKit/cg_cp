#pragma once

#include "ReaderSolution.h"
#include "DirectorSolution.h"
#include "Model.h"
#include <assert.h>

class LoadManager
{
protected:
    ReaderSolution readerSolution;
    DirectorSolution directorSolution;

public:
    LoadManager();

    std::shared_ptr<Model> loadModelFromFile(idReaderCreator id_reader, 
                                                    idDirectorCreator id_director, 
                                                    const char *filename, 
                                                    size_t stepOfRevolving,
                                                    std::shared_ptr<Material> material);
    std::shared_ptr<Model> loadChessboardFromFile(idReaderCreator id_reader, 
                                                    idDirectorCreator id_director, 
                                                    const char *fnBlackCells,
                                                    std::shared_ptr<Material> matBlackCells, 
                                                    const char *fnWhiteCells,
                                                    std::shared_ptr<Material> matWhiteCells, 
                                                    const char *fnBase,
                                                    std::shared_ptr<Material> matBase);
};
