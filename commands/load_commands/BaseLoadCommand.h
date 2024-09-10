#pragma once

#include "BaseCommand.h"
#include "LoadManager.h"

class BaseLoadCommand : public BaseCommand 
{
protected:
    idReaderCreator id_reader;
    idDirectorCreator id_director;
    std::shared_ptr<Material> material;

public:
    BaseLoadCommand(std::shared_ptr<Material> _material);
    virtual ~BaseLoadCommand() = 0;

    idReaderCreator getReaderId();
    idDirectorCreator getDirectorId();

    virtual void execute() = 0;
};