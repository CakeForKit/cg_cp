#include "TransformCommand.h"

class MoveCommand : public TransformCommand
{
protected:
    // PtrObjectScene model;
    size_t idModel;
    double dx, dy, dz;

public:
    MoveCommand() = delete;
    MoveCommand(size_t _idModel, double _dx, double _dy, double _dz);

    virtual void execute();
};
