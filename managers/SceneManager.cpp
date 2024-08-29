#include "SceneManager.h"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Scene> SceneManager::getScene() noexcept {
    return scene;
}

void SceneManager::addModel(std::shared_ptr<ObjectScene> model) noexcept {
    scene->addModel(model);
}

void SceneManager::removeModel(size_t ind) {
    scene->removeModel(ind);
}

void SceneManager::addCamera() noexcept {
    scene->addCamera();
}

void SceneManager::removeCamera(size_t ind) {
    scene->removeCamera(ind);
}
