#include "Matrix4.h"

Matrix4::Matrix4() : mat(glm::mat4(1.0f)) {}

Matrix4::Matrix4(glm::mat4 &&m) : mat(m) {}


Matrix4& Matrix4::operator=(const Matrix4 &m) noexcept {
    mat = m.getGlm();
}

Matrix4& Matrix4::operator=(Matrix4 &&m) noexcept {
    mat = m.getGlm();
}

// double Matrix4::operator[](size_t ind) const {
//     return mat[int];
// }

// double &Matrix4::operator[](size_t ind);

Matrix4 Matrix4::operator*(const Matrix4 &m) const noexcept {
    return mat * m.getGlm();
}

Matrix4 Matrix4::operator*(const Matrix4 &&m) const noexcept {
    return mat * m.getGlm();
}

Matrix4& Matrix4::operator*=(const Matrix4 &m) noexcept {
    mat *= m.getGlm();
    return *this;
}
Matrix4& Matrix4::operator*=(const Matrix4 &&m) noexcept {
    mat *= m.getGlm();
    return *this;
}

const glm::mat4 &Matrix4::getGlm() const {
    return mat;
}

Vector3 operator*(Matrix4 &m, Vector3 &v) {
    glm::vec4 v4(v.x(), v.y(), v.z(), 1);
    v4 = m.getGlm() * v4;
    return Vector3(v4[0], v4[1], v4[2], v4[3]);
}