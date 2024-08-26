#include "Scene.h"

std::ostream& operator<<(std::ostream &os, const Scene &scene) {
    return scene.print(os);
}

std::ostream& Scene::print(std::ostream& os) const noexcept {
    os << "Scene: \n";
    os << "Cameras: ----------\n";
    size_t i = 0;
    for (std::shared_ptr<Camera> elem : cameras) {
        os << i << ") " << *elem;
        ++i;
    }
    os << "-------------------\n";
    // for (std::shared_ptr<ObjectScene> elem : models)
    //     os << *elem;

    return os;
}

Scene::Scene() 
: models(std::vector<std::shared_ptr<ObjectScene>>()), cameras(std::vector<std::shared_ptr<Camera>>()) {
    cameras.push_back(std::make_shared<Camera>());
}

void Scene::addCamera() noexcept {
    cameras.push_back(std::make_shared<Camera>());
}

void Scene::removeCamera(size_t ind) {
    size_t count_camera = cameras.size();
    if (count_camera == 1) {
        time_t curTime = time(NULL);
        throw LastCameraSceneException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    if (ind >= count_camera) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    cameras.erase(cameras.begin() + static_cast<long int>(ind));
}

std::shared_ptr<Camera> Scene::getCamera(size_t ind) const {
    if (ind >= cameras.size()) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return cameras[ind];
}

