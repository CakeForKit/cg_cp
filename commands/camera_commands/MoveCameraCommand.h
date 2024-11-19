#pragma once
#include "BaseCommand.h"

class MoveCameraCommand : public BaseCommand
{
protected:
    double length;

public:
    MoveCameraCommand() = delete;
    MoveCameraCommand(double _length);

    virtual void execute();
};
