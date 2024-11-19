#include "RemoveModelCommand.h"


RemoveModelCommand::RemoveModelCommand(size_t _idModel)
: TransformCommand(_idModel) {}

void RemoveModelCommand::execute() {
    sceneManager->removeModel(idModel);
}