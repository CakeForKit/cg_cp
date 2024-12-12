#include "RotateCameraCommand.h"

RotateCameraCommand::RotateCameraCommand(float _angle_grad, Axis _axis)
: angle_grad(_angle_grad), axis(_axis) {}

// RotateCameraCommand::RotateCameraCommand(float _angle_grad, Dir _dir)
// : angle_grad(_angle_grad), dir(_dir) {}

void RotateCameraCommand::execute() {
    std::shared_ptr<Camera> camera = sceneManager->getActiveCamera();
    Vector3 vec_axis = camera->getAxis(axis);

    // std::cout << "\nBefore camera:\n" << *camera;
    transformManager->rotateCamera(camera, angle_grad, vec_axis);
    // std::cout << "Rotated camera:\n" << *camera;
}