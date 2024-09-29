#include "MoveCommand.h"

MoveCommand::MoveCommand(PtrObjectScene _model, double _dx, double _dy, double _dz)
: model(_model), dx(_dx), dy(_dy), dz(_dz) {}

void MoveCommand::execute() {
    transformManager->moveModel(model, dx, dy, dz);
}