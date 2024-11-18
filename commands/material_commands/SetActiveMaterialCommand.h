#pragma once

#include "BaseLoadCommand.h"

class SetActiveMaterialCommand : public BaseLoadCommand
{
protected:
    idPairMaterial idPairMat;

public:
    SetActiveMaterialCommand() = delete;
    SetActiveMaterialCommand(idPairMaterial _idPairMaterial);

    virtual void execute();
};
