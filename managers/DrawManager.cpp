#include "DrawManager.h"

void DrawManager::drawScene(std::shared_ptr<Scene> scene, size_t indexCamera, std::shared_ptr<Drawer> drawer) {
    std::shared_ptr<Camera> camera = scene->getCamera(indexCamera);
    std::shared_ptr<RayTracing> rayTracing = std::make_shared<StandardRayTracing>(scene, camera, drawer);

    rayTracing->render()
}