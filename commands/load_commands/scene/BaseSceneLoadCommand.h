#pragma once

// #include "BaseLoadCommand.h"
#include "dataMaps.h"

class BaseSceneLoadCommand : public BaseLoadCommand
{
protected:
    DataMaps fnMaps;
    size_t stepOfRevolving;

public:
    BaseSceneLoadCommand() = delete;
    BaseSceneLoadCommand(DataMaps &_fnMaps, 
                            size_t _stepOfRevolving);

    // virtual void execute();

protected:
    void loadModel(std::shared_ptr<Material> material, typeChess tChess, size_t pi, size_t pj);
};
