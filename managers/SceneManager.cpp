#include "SceneManager.h"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Scene> SceneManager::getScene() noexcept {
    return scene;
}

void SceneManager::clearScene() noexcept {
    scene->deleteAllModels();
}

size_t SceneManager::getCountAllFaces() const noexcept {
    return scene->getCountAllFaces();
}

size_t SceneManager::countModels() const noexcept {
    return scene->countModels();
}

void SceneManager::addModel(std::shared_ptr<Model> model, size_t i, size_t j) {
    scene->addModel(model, i, j);
}

void SceneManager::removeModel(size_t ind) {
    scene->removeModel(ind);
}

std::shared_ptr<Model> SceneManager::getModel(size_t ind) {
    return scene->getModel(ind);
}

bool SceneManager::getPosModel(size_t idModel, size_t &i, size_t &j) const noexcept {
    return scene->getPosModel(idModel, i, j);
}

// void SceneManager::addCamera() noexcept {
//     scene->addCamera();
// }

// void SceneManager::removeCamera(size_t ind) {
//     scene->removeCamera(ind);
// }

std::shared_ptr<Camera> SceneManager::getActiveCamera() {
    return scene->getActiveCamera();
}

void SceneManager::setChessboard(std::shared_ptr<Chessboard> model) noexcept {
    scene->setChessboard(model);
}

Point3 SceneManager::changeModelPos(size_t idModel, size_t i, size_t j) {
    return scene->changeModelPos(idModel, i, j);
}

// Point3 SceneManager::getPosCell(size_t i, size_t j) const {
//     return scene->getPosCell(i, j);
// }
