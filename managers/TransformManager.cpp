#include "TransformManager.h"

void TransformManager::moveModel(PtrModel model, double dx, double dy, double dz) {
    std::shared_ptr<TransformAction> action = std::make_shared<MoveAction>(dx, dy, dz);
    model->transform(action);
}


void TransformManager::rotateModel(PtrModel model, float angle) {
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
                                                                            model->getCenter(), 
                                                                            Axis::OY);
    model->transform(action);
}

void TransformManager::rotateCamera(std::shared_ptr<Camera> camera, float angle, Axis axis) {
    // Vector3 axisVec = camera->getAxis(axis);
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
                                                                            camera->getCameraPos(), 
                                                                            axis);
    camera->transform(action);
    std::cout << "TransformManager::rotateCamera\n" << *camera << "\n"; 
}
