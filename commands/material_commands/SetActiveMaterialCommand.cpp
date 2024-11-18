#include "SetActiveMaterialCommand.h"


SetActiveMaterialCommand::SetActiveMaterialCommand(idPairMaterial _idPairMaterial)
: idPairMat(_idPairMaterial) {}

void SetActiveMaterialCommand::execute() {
    assert(materialManager->changeActiveMaterial(idPairMat));
}