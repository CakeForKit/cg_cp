#include "TransformManager.h"

void TransformManager::moveModel(PtrObjectScene model, double dx, double dy, double dz) {
    std::shared_ptr<TransformAction> action = std::make_shared<MoveAction>(dx, dy, dz);
    model->transform(action);
}

void TransformManager::rotateModel(PtrObjectScene model, float angle) {
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle);
    model->transform(action);
}
