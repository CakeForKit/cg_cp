#include "TransformCommand.h"

class MoveCommand : public TransformCommand
{
protected:
    PtrObjectScene model;
    double dx, dy, dz;

public:
    MoveCommand() = delete;
    MoveCommand(PtrObjectScene _model, double _dx, double _dy, double _dz);

    virtual void execute();
};
