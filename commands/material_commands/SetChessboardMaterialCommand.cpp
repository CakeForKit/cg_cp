#include "SetChessboardMaterialCommand.h"


SetChessboardMaterialCommand::SetChessboardMaterialCommand(idChessboardMaterial _id)
: id(_id) {}

void SetChessboardMaterialCommand::execute() {
    materialManager->setChessboardMaterial(id);
}