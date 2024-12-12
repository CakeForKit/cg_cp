#pragma once

#include <gtest/gtest.h>
#include <initializer_list>
#include <vector>

#include "Ray.h"


struct ray_test_data_t {
    Ray ray;
    Point3 point;
    double expDist2;
};

const ray_test_data_t ray_test_data[] = {
    {Ray(Point3(1, -2, 0), Vector3(0, 1, 0)), Point3(0, 0, 0), 1},
    {Ray(Point3(1, 1, 0), Vector3(1, 1, 0)), Point3(0, 0, 0), 0},
    {Ray(Point3(1, 2, 3), Vector3(1, 2, -3)), Point3(0, 0, 0), 12.857142857142858}
};