#include "TransformCommand.h"

class RotateCommand : public TransformCommand
{
protected:
    size_t idModel;
    float angle_grad;

public:
    RotateCommand() = delete;
    RotateCommand(size_t _idModel, float _angle_grad);

    virtual void execute();
};
