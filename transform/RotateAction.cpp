#include "RotateAction.h"

RotateAction::RotateAction(float angle_grad) {
    // (void)angle_grad;
    mat = Matrix4(glm::rotate(glm::mat4(1.0f), glm::radians(angle_grad), glm::vec3(0.0, 1.0, 0.0)));
}