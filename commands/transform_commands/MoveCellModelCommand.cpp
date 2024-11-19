#include "MoveCellModelCommand.h"

MoveCellModelCommand::MoveCellModelCommand(size_t _idModel, size_t _i, size_t _j) 
: TransformCommand(_idModel), i(_i), j(_j) {}

void MoveCellModelCommand::execute() {
    PtrModel model = sceneManager->getModel(idModel);
    Point3 diff = sceneManager->changeModelPos(idModel, i, j);
    transformManager->moveModel(model, diff.x(), diff.y(), diff.z());
    // std::cout << "MoveCellModelCommand:\nfrom: " << i << " " << j << "\nto " << diff << "\n";
}