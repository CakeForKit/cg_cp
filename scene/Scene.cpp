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
    os << "Models: ----------\n";
    i = 0;
    for (std::shared_ptr<Model> elem : models) {
        os << i << ") " << *elem;
        ++i;
    }
    os << "-------------------\n";

    return os;
}

Scene::Scene() 
: models(std::vector<std::shared_ptr<Model>>()), 
cameras(std::vector<std::shared_ptr<Camera>>()), 
lights(std::vector<std::shared_ptr<Light>>()) {
    std::shared_ptr<Camera> c = std::make_shared<Camera>();
    cameras.push_back(c);
    activeCamera = cameras[0];

    lights.push_back(std::make_shared<PointLight>());
    lights.push_back(std::make_shared<AmbientLight>());

    for (size_t i = 0; i < 8; ++i)
        for (size_t j = 0; j < 8; ++j)
            posModels[i][j] = -1;
}

void Scene::addModel(std::shared_ptr<Model> model, size_t i, size_t j) {
    if (i >= 8 || j >= 8) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    if (!checkPosModel(i, j)) {
        time_t curTime = time(NULL);
        throw BusyPosSceneException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    models.push_back(model);
    posModels[i][j] = static_cast<int>(models.size() - 1);
    // for (size_t i = 0;i < 8; ++i) {
    //     for (size_t j = 0; j < 8; ++j) {
    //         std::cout << posModels[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
}

void Scene::removeModel(size_t ind) {
    std::cout << "Scene::removeModel-----\n\n";
    size_t count_models = models.size();
    std::cout << "count_models = " << count_models << "\n";
    std::cout << "ind = " << ind << "\n";
    if (count_models == 0) {
        time_t curTime = time(NULL);
        throw NoModelsSceneException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    if (ind >= count_models) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    std::cout << "count_models = " << count_models << "\n";
    int id = static_cast<int>(ind);
    for (size_t i = 0;i < 8; ++i) 
        for (size_t j = 0; j < 8; ++j) {
            if (posModels[i][j] > id)
                posModels[i][j]--;
            else if (posModels[i][j] == id)
                posModels[i][j] = -1;
        }
            
    std::cout << "before rm len = " << models.size() << "\n";
    models.erase(models.begin() + id);
    std::cout << "after rm len = " << models.size() << "\n";
}

std::shared_ptr<Model> Scene::getModel(size_t ind) {
    size_t count_models = models.size();
    if (count_models == 0) {
        time_t curTime = time(NULL);
        throw NoModelsSceneException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    if (ind >= count_models) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return models[ind];
}

size_t Scene::countModels() const noexcept {
    return models.size();
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

std::shared_ptr<Camera> Scene::getCamera(size_t ind) {
    if (ind >= cameras.size()) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return cameras[ind];
}

void Scene::setActiveCamera(size_t ind) {
    activeCamera = getCamera(ind);
}

std::shared_ptr<Camera> Scene::getActiveCamera() noexcept {
    return activeCamera;
}

Scene::iteratorLight Scene::beginLight() const noexcept {
    return lights.begin();
}

Scene::iteratorLight Scene::endLight() const noexcept {
    return lights.end();
}

void Scene::setChessboard(std::shared_ptr<Chessboard> model) noexcept {
    chessboard = model;
    chessborad_set = true;
}

Point3 Scene::changeModelPos(size_t idModel, size_t i, size_t j) {
    int id = static_cast<int>(idModel);
    assert(models.size() > idModel);
    
    if (posModels[i][j] >= 0 && posModels[i][j] != id) {
        time_t curTime = time(NULL);
        throw BusyPosSceneException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    for (size_t i = 0;i < 8; ++i) 
        for (size_t j = 0; j < 8; ++j)
            if (posModels[i][j] == id)
                posModels[i][j] = -1;
    PtrModel model = getModel(idModel);
    posModels[i][j] = id;
    
    Point3 newposCell, oldposCell, diff;
    newposCell = getPosCell(i, j);
    oldposCell  = model->getCenter();
    diff = newposCell - oldposCell;

    return diff;
}

Point3 Scene::getPosCell(size_t i, size_t j) const {
    return chessboard->getPosCell(i, j);
}

bool Scene::getPosModel(size_t idModel, size_t &ni, size_t &nj) const noexcept {
    for (size_t i = 0; i < 8; ++i)
        for (size_t j = 0; j < 8; ++j)
            if (posModels[i][j] == static_cast<int>(idModel)) {
                ni = i;
                nj = j;
                return true;
            }
    return false;
}

bool Scene::checkPosModel(size_t i, size_t j) const noexcept {
    return i < 8 && j < 8 && posModels[i][j] == -1;
}

bool Scene::intersection(const Ray &ray, intersection_t &intersect) const {
    intersection_t closest_intersect, now_intersect;
    closest_intersect.distance = std::numeric_limits<double>::max();

    if (chessborad_set && show_chessboard)
        chessboard->intersection(ray, closest_intersect);
    for (std::shared_ptr<Model> model : models) {
        if (model->intersection(ray, now_intersect) && now_intersect.distance < closest_intersect.distance) {
            closest_intersect = now_intersect;
        }
    }

    // std::cout << "Scene::intersection:\n";
    // std::cout << "Ray: " << ray << std::endl;

    if (fabs(std::numeric_limits<double>::max() - closest_intersect.distance) < EPS)
        return false;

    intersect = closest_intersect;

    // std::cout << "\t" << intersect << std::endl;
    
    return true;
}

void Scene::deleteAllModels() noexcept {
    models.clear();
    for (size_t i = 0; i < 8; ++i)
        for (size_t j = 0; j < 8; ++j)
            posModels[i][j] = -1;
}

size_t Scene::getCountAllFaces() const noexcept {
    size_t count = 0;
    for (std::shared_ptr<Model> m: models) {
        count += m->getCountFaces();
    }
    return count;
}