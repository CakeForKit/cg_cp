#include "TrianglesModelLoadCommand.h"

// TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename, size_t _stepOfRevolving, idMaterial _id_material) 
// : filename(_filename), stepOfRevolving(_stepOfRevolving), id_material(_id_material) { 
//     id_director = idDirectorCreator::TRIANGLES; 
//     id_reader = idReaderCreator::TRIANGLES;
// }

TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename, 
                                                    size_t _stepOfRevolving, 
                                                    indPair _indPairMaterial,
                                                    typeChess _type,
                                                    size_t _i, size_t _j) 
: filename(_filename), stepOfRevolving(_stepOfRevolving), indPairMaterial(_indPairMaterial), 
type(_type), pi(_i), pj(_j) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesModelLoadCommand::execute() {
    // std::shared_ptr<Material> material = materialManager->getMaterial(id_material);
    std::shared_ptr<Material> material = materialManager->getActiveMaterial(indPairMaterial);
    PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
    std::cout << "TrianglesModelLoadCommand::execute\n";
    std::cout << *model << "\n";
    model->setTypeChess(type);
    sceneManager->addModel(model, pi, pj);

    size_t idModel = sceneManager->countModels() - 1;
    Point3 diff = sceneManager->changeModelPos(idModel, pi, pj);
    transformManager->moveModel(model, diff.x(), diff.y(), diff.z());
}