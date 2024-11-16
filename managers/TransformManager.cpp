#include "TransformManager.h"

void TransformManager::moveModel(PtrModel model, double dx, double dy, double dz) {
    std::shared_ptr<TransformAction> action = std::make_shared<MoveAction>(dx, dy, dz);
    model->transform(action);
}

void TransformManager::moveModel(PtrModel model, size_t i, size_t j) {
    if (i >= 8 || j >= 8) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
}

void TransformManager::rotateModel(PtrModel model, float angle) {
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
                                                                            model->getCenter(), 
                                                                            Axis::OY);
    model->transform(action);
}

void TransformManager::rotateCamera(std::shared_ptr<Camera> camera, float angle, Axis axis) {
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
                                                                            camera->getCameraPos(), 
                                                                            axis);
    camera->transform(action);
}
