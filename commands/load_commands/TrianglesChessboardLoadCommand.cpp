#include "TrianglesChessboardLoadCommand.h"

TrianglesChessboardLoadCommand::TrianglesChessboardLoadCommand(const char *_fnBlackCells,
                                                            idMaterial _id_matBlackCells, 
                                                            const char *_fnWhiteCells,
                                                            idMaterial _id_matWhiteCells, 
                                                            const char *_fnBase,
                                                            idMaterial _id_matBase) 
: fnBlackCells(_fnBlackCells), fnWhiteCells(_fnWhiteCells), fnBase(_fnBase),
id_matBlackCells(_id_matBlackCells), id_matWhiteCells(_id_matWhiteCells), id_matBase(_id_matBase) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesChessboardLoadCommand::execute() {
    std::shared_ptr<Material> matBlackCells = materialManager->getMaterial(id_matBlackCells);
    std::shared_ptr<Material> matWhiteCells = materialManager->getMaterial(id_matWhiteCells);
    std::shared_ptr<Material> matBase = materialManager->getMaterial(id_matBase);
    PtrModel model = loadManager->loadChessboardFromFile(id_reader, id_director, 
                                                        fnBlackCells, matBlackCells,
                                                        fnWhiteCells, matWhiteCells, 
                                                        fnBase, matBase);

    sceneManager->addModel(model);
}