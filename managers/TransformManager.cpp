#include "TransformManager.h"

void TransformManager::moveModel(PtrModel model, double dx, double dy, double dz) {
    std::shared_ptr<TransformAction> action = std::make_shared<MoveAction>(dx, dy, dz);
    model->transform(action);
}


void TransformManager::rotateModel(PtrModel model, float angle) {
    Vector3 c = model->getCenter();
    std::shared_ptr<TransformAction> to_center = std::make_shared<MoveAction>(-c.x(), -c.y(), -c.z());
    model->transform(to_center);
    std::cout << "to center:\n" << *to_center;

    std::shared_ptr<TransformAction> rotate = std::make_shared<RotateAction>(angle, 
                                                                                model->getCenter(), 
                                                                                Axis::OY);
    model->transform(rotate);
    std::cout << "rotate:\n" << *rotate;     

    std::shared_ptr<TransformAction> from_center = std::make_shared<MoveAction>(c.x(), c.y(), c.z());      
    model->transform(from_center);
    std::cout << "from center:\n" << *from_center;                                                
    // std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
    //                                                                         model->getCenter(), 
    //                                                                         Axis::OY);
    // model->transform(action);
}

void TransformManager::moveCamera(std::shared_ptr<Camera> camera, double length) {
    Vector3 pos, newPos;
    pos = camera->getCameraPos();
    newPos = pos.cut(length) - pos;
    std::shared_ptr<TransformAction> action = std::make_shared<MoveAction>(newPos.x(), newPos.y(), newPos.z());
    camera->transform(action);
}

void TransformManager::rotateCamera(std::shared_ptr<Camera> camera, float angle, Axis axis) {
    std::shared_ptr<TransformAction> action = std::make_shared<RotateAction>(angle, 
                                                                            camera->getCameraPos(), 
                                                                            axis);
    camera->transform(action);
    // std::cout << "TransformManager::rotateCamera\n" << *camera << "\n"; 
}
