#include "TrianglesModelLoadCommand.h"

TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename, size_t _stepOfRevolving, idMaterial _id_material) 
: filename(_filename), stepOfRevolving(_stepOfRevolving), id_material(_id_material) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesModelLoadCommand::execute() {
    std::shared_ptr<Material> material = materialManager->getMaterial(id_material);
    PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);

    sceneManager->addModel(model);
}