#include "TrianglesModelLoadCommand.h"

TrianglesModelLoadCommand::TrianglesModelLoadCommand(const char *_filename) 
: filename(_filename) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
}
    
void TrianglesModelLoadCommand::execute() {
    PtrObjectScene model = loadManager->loadModelFromFile(id_reader, id_director, filename);

    sceneManager->addModel(model);
}