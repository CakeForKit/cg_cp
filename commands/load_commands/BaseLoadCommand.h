#pragma once

#include "BaseCommand.h"
#include "LoadManager.h"

enum class typeScenes {
    BEGIN,
    ALLBYONE,
    TEST
};

class BaseLoadCommand : public BaseCommand 
{
protected:
    idReaderCreator id_reader;
    idDirectorCreator id_director;

public:
    // BaseLoadCommand(idMaterial _id_material);
    virtual ~BaseLoadCommand() = 0;

    idReaderCreator getReaderId();
    idDirectorCreator getDirectorId();

    virtual void execute() = 0;
};