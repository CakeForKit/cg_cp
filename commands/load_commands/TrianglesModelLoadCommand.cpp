#include "TrianglesModelLoadCommand.h"

TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename, std::shared_ptr<Material> _material) 
: BaseLoadCommand(_material), filename(_filename) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesModelLoadCommand::execute() {
    PtrObjectScene model = loadManager->loadModelFromFile(id_reader, id_director, filename, material);

    sceneManager->addModel(model);
}