#pragma once

#include "BaseCommand.h"
#include "LoadManager.h"

class BaseLoadCommand : public BaseCommand 
{
public:
    virtual ~BaseLoadCommand() = 0;

    idReaderCreator getReaderId();
    idDirectorCreator getDirectorId();

    virtual void execute() = 0;
    
protected:
    idReaderCreator id_reader;
    idDirectorCreator id_director;
};