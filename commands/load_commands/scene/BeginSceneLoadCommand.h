#pragma once

#include "BaseSceneLoadCommand.h"

class BeginSceneLoadCommand : public BaseSceneLoadCommand
{
public:
    BeginSceneLoadCommand() = delete;
    BeginSceneLoadCommand(DataMaps &_fnMaps, 
                            size_t _stepOfRevolving);

    virtual void execute();

private:
    void loadPlayerModels(indPair indPairMaterial);
};
