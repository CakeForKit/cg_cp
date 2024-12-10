#pragma once

#include "BaseLoadCommand.h"

class TestSceneLoadCommand : public BaseLoadCommand
{
private:
    size_t stepOfRevolving;
    
public:
    TestSceneLoadCommand() = delete;
    TestSceneLoadCommand(size_t _stepOfRevolving);

    virtual void execute();
};
