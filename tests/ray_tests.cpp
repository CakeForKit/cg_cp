#include "ray_tests.h"

class TestRay : public testing::TestWithParam<ray_test_data_t> {};

TEST_P(TestRay, StandartBasis) {
    ray_test_data_t tdata = GetParam();

    Ray ray = tdata.ray;
    Point3 p = tdata.point;
    double dist2 = ray.dist2ToPoint(p);
    // std::cout << ""
    EXPECT_TRUE(fabs(dist2 - tdata.expDist2) < EPS);
}



INSTANTIATE_TEST_SUITE_P(
    RayTestSuite,
    TestRay,
    testing::Values(ray_test_data[0], ray_test_data[1])
);
