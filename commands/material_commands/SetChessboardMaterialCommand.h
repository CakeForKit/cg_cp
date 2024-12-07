#pragma once

#include "BaseLoadCommand.h"

class SetChessboardMaterialCommand : public BaseLoadCommand
{
protected:
    idChessboardMaterial id;

public:
    SetChessboardMaterialCommand() = delete;
    SetChessboardMaterialCommand(idChessboardMaterial _id);

    virtual void execute();
};
