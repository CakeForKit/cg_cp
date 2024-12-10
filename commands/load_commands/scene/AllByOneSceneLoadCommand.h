#pragma once

#include "BaseSceneLoadCommand.h"

class AllByOneSceneLoadCommand : public BaseSceneLoadCommand
{
public:
    AllByOneSceneLoadCommand() = delete;
    AllByOneSceneLoadCommand(DataMaps &_fnMaps, 
                            size_t _stepOfRevolving);

    virtual void execute();
};
