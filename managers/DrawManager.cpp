#include "DrawManager.h"

void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, std::shared_ptr<Drawer> drawer) {
    size_t pixelsWidth = static_cast<size_t>(drawer->getImgWidth());
    size_t pixelsHeight = static_cast<size_t>(drawer->getImgHeight());
    camera->setCountPixelsViewport(pixelsWidth, pixelsHeight);
    std::shared_ptr<RayTracing> rayTracing = std::make_shared<StandardRayTracing>(scene, camera, drawer);

    std::cout << "DrawManager::drawScene    scene\n" << *scene << std::endl;
    rayTracing->render();
}