#include "TrianglesChessboardLoadCommand.h"

TrianglesChessboardLoadCommand::TrianglesChessboardLoadCommand(const char *_fnBlackCells,
                                                            idMaterial _id_matBlackCells, 
                                                            const char *_fnWhiteCells,
                                                            idMaterial _id_matWhiteCells, 
                                                            const char *_fnBase,
                                                            idMaterial _id_matBase,
                                                            const char *_fnDataCellsReader) 
: fnBlackCells(_fnBlackCells), fnWhiteCells(_fnWhiteCells), fnBase(_fnBase), fnDataCellsReader(_fnDataCellsReader),
id_matBlackCells(_id_matBlackCells), id_matWhiteCells(_id_matWhiteCells), id_matBase(_id_matBase) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesChessboardLoadCommand::execute() {
    std::shared_ptr<Material> matBlackCells = materialManager->getMaterial(id_matBlackCells);
    std::shared_ptr<Material> matWhiteCells = materialManager->getMaterial(id_matWhiteCells);
    std::shared_ptr<Material> matBase = materialManager->getMaterial(id_matBase);
    std::shared_ptr<Model> model = loadManager->loadChessboardFromFile(id_reader, id_director, 
                                                        fnBlackCells, matBlackCells,
                                                        fnWhiteCells, matWhiteCells, 
                                                        fnBase, matBase,
                                                        fnDataCellsReader);
    std::shared_ptr<Chessboard> chessboard = std::dynamic_pointer_cast<Chessboard>(model);
    sceneManager->setChessboard(chessboard);
}