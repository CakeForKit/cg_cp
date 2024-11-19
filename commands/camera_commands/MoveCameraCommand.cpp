#include "MoveCameraCommand.h"


MoveCameraCommand::MoveCameraCommand(double _length)
: length(_length) {}

void MoveCameraCommand::execute() {
    std::shared_ptr<Camera> camera = sceneManager->getActiveCamera();
    transformManager->moveCamera(camera, length);
}