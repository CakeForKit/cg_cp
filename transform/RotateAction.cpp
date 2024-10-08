#include "RotateAction.h"

RotateAction::RotateAction(float angle_grad, Point3 &&center, Axis axis) {
    glm::vec3 axisVec;
    if (axis == Axis::OY) {
        axisVec = glm::vec3(0.0, 1.0, 0.0);
    } else if (axis == Axis::OX) {
        axisVec = glm::vec3(1.0, 0.0, 0.0);
    } else if (axis == Axis::OZ) {
        axisVec = glm::vec3(0.0, 0.0, 1.0);
    } else {
        assert(false);
    }

    // ЗАЧЕМ Я ЦЕНТРИРУЮ
    glm::mat4 tmp = glm::translate(glm::mat4(1.0f), glm::vec3(-center .x(), -center .y(), -center .z()));
    std::cout << "Mat4:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << tmp[i][j] << " ";
        }
        std::cout << "\n";
    }
    glm::mat4 helptmp = glm::rotate(glm::mat4(1.0f), glm::radians(angle_grad), axisVec);
    tmp = helptmp * tmp;
    std::cout << "Mat4:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << tmp[i][j] << " ";
        }
        std::cout << "\n";
    }
    tmp = glm::translate(glm::mat4(1.0f), glm::vec3(center .x(), center .y(), center .z())) * tmp;
    mat = Matrix4(tmp);
}