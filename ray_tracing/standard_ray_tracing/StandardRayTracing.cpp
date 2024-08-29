#include "StandardRayTracing.h"

StandardRayTracing::StandardRayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer)
: RayTracing(_scene, _camera, _drawer) {}

Color StandardRayTracing::castRay(Ray &ray) const noexcept {

    intersection_t intersect;
    if (scene->intersection(ray, intersect)) {
        return Color(255, 0, 0);
    } else {
        return Color(0, 0, 0);
    }

    // Vector3 unit_dir = ray.getDirection();
    // if (fabs(unit_dir.y()) < EPS + 10) {
    //     return Color(0, 0, 255);
    // }
    // else if  (unit_dir.y() >= 0) {
    //     return Color(255, 0, 0);
    // }
    // else {
    //     return Color(0, 255, 0);
    // }
}

void StandardRayTracing::render() {
    for (int j = 0; j < drawer->getImgHeight(); ++j) {
        for (int i = 0; i < drawer->getImgWidth(); ++i) {
            // std::cout << "(" << i << ", " << j << ")\n";
            Ray ray = camera->createRay(i, j);
            Color color = castRay(ray);
            drawer->setPixelColor(i, j, color);
        }
    }
    drawer->setScene();
}