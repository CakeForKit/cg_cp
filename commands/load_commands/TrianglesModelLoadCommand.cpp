#include "TrianglesModelLoadCommand.h"

TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename, idMaterial _id_material) 
: BaseLoadCommand(_id_material), filename(_filename) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesModelLoadCommand::execute() {
    std::shared_ptr<Material> material = materialManager->getMaterial(id_material);
    PtrObjectScene model = loadManager->loadModelFromFile(id_reader, id_director, filename, material);

    sceneManager->addModel(model);
}