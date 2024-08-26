#include <gtest/gtest.h>
#include <initializer_list>
#include <vector>

#include "Camera.h"

struct ij_coord_t {
    size_t i; size_t j;
    Point3 expectCoord;
};

struct camera_test_data_t {
    float focalLength;
    float viewportHeight;
    size_t countPixelsWidth;
    size_t countPixelsHeight;
    Vector3 cameraPos;
    std::vector<ij_coord_t> res;
};

class TestCamera : public testing::TestWithParam<camera_test_data_t> {};

TEST_P(TestCamera, StandartBasis) {
    camera_test_data_t tdata = GetParam();

    Camera cam;
    cam.setFocalLength(tdata.focalLength, false);
    cam.setViewportHeight(tdata.viewportHeight, false);
    cam.setCameraPos(tdata.cameraPos, false);
    cam.setCountPixelsViewport(tdata.countPixelsWidth, tdata.countPixelsHeight);

    std::vector<ij_coord_t> dataRes = tdata.res;
    for (ij_coord_t elem : dataRes) {
        Ray ray = cam.createRay(elem.i, elem.j);
        Point3 pointCoord = ray.getDirection() + tdata.cameraPos;

        // std::cout << "elem: (" << elem.i << ", " << elem.j << ", " << elem.expectCoord << std::endl;
        // cam.print();
        std::cout << cam;
        // std::cout << "\npointCoord = " << pointCoord << "\n\n";
        EXPECT_TRUE(pointCoord == elem.expectCoord);
    }
}

const camera_test_data_t camera_test_data[] = {
    {
        10, 100, 6, 4, Vector3(0, 0, 10), 
        {
            {0, 0, Point3(-75 + 12.5, 50 - 12.5, 0)},
            {5, 0, Point3(-75 + 12.5 + 25 * 5, 50 - 12.5, 0)},
            {0, 3, Point3(-75 + 12.5, 50 - 12.5 - 25 * 3, 0)},
            {5, 3, Point3(-75 + 12.5 + 25 * 5, 50 - 12.5 - 25 * 3, 0)},
            // {3, 1, Point3(-75 + 12.5+ 25 * 3, 50 - 12.5 - 25 * 1, 0)},
        }
    }
};

INSTANTIATE_TEST_SUITE_P(
    CameraTestSuite,
    TestCamera,
    testing::Values(camera_test_data[0])
);
