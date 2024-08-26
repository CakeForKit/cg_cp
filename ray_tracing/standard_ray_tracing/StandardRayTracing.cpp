#include "StandardRayTracing.h"

StandardRayTracing::StandardRayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer)
: RayTracing(_scene, _camera, _drawer) {}

Color StandardRayTracing::castRay(Ray &ray) const noexcept {
    return Color(255, 0, 0);
}

void StandardRayTracing::render() {
    for (size_t j = 0; j < drawer->getImgHeight(); ++j) {
        for (size_t i = 0; i < drawer->getImgWidth(); ++i) {
            Ray ray = camera->createRay(i, j);
            Color color = castRay(ray);
            drawer->setPixelColor(i, j, color);
        }
    }
    drawer->setScene();
}