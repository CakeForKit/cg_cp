#pragma once
#include "BaseCommand.h"

class ClearSceneCommand : public BaseCommand
{
public:
    ClearSceneCommand();

    virtual void execute();
};
