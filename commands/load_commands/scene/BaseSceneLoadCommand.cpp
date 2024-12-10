#include "BaseSceneLoadCommand.h"


BaseSceneLoadCommand::BaseSceneLoadCommand(DataMaps &_fnMaps,
                                                size_t _stepOfRevolving) 
: fnMaps(_fnMaps), stepOfRevolving(_stepOfRevolving) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}

void BaseSceneLoadCommand::loadModel(std::shared_ptr<Material> material, 
                                        typeChess tChess, 
                                        size_t pi, size_t pj) 
{
    const char *filename = fnMaps.getFilename(tChess);
    PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
    model->setTypeChess(tChess);
    sceneManager->addModel(model, pi, pj);

    size_t idModel = sceneManager->countModels() - 1;
    Point3 diff = sceneManager->changeModelPos(idModel, pi, pj);
    transformManager->moveModel(model, diff.x(), diff.y(), diff.z());
}