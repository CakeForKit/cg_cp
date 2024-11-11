#pragma once

#include "Vector3.h"
#include "Material.h"

struct intersection_t {
    Point3 point;       // Точка пересечение
    double distance;    // Расстояние от начала луча до точки пересечения
    Vector3 normal;     // Нормаль к пересекаемой плоскости
    std::shared_ptr<Material> material;

    intersection_t& operator=(const intersection_t &v) noexcept;
    intersection_t& operator=(intersection_t &&v) noexcept;
};

std::ostream& operator<<(std::ostream &os, const intersection_t &interset);