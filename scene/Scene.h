#pragma once

#include "Model.h"
#include "Camera.h"
#include "Light.h"
#include "Chessboard.h"

class Scene
{
public:
    using iteratorLight = std::vector<std::shared_ptr<Light>>::const_iterator;

protected:
    std::vector<std::shared_ptr<Model>> models;
    int posModels[8][8];
    std::shared_ptr<Chessboard> chessboard;
    bool chessborad_set = false;
    std::vector<std::shared_ptr<Camera>> cameras;
    std::shared_ptr<Camera> activeCamera; // указатель на камеру через которую сейчас смотрим. Один из элементов cameras
    std::vector<std::shared_ptr<Light>> lights;

public:
    Scene();

    void addModel(std::shared_ptr<Model> model, size_t i, size_t j);
    void addModel(std::shared_ptr<Model> model);
    void removeModel(size_t ind);
    void deleteAllModels() noexcept;
    std::shared_ptr<Model> getModel(size_t ind);
    size_t countModels() const noexcept;

    void addCamera() noexcept;
    void removeCamera(size_t ind);
    std::shared_ptr<Camera> getCamera(size_t ind);
    void setActiveCamera(size_t ind);
    std::shared_ptr<Camera> getActiveCamera() noexcept;

    iteratorLight beginLight() const noexcept;
    iteratorLight endLight() const noexcept;
    // std::shared_ptr<Light> getLight() noexcept;

    void setChessboard(std::shared_ptr<Chessboard> model) noexcept;
    // return Point3(dx, dy, dz)
    Point3 changeModelPos(size_t idModel, size_t i, size_t j);
    Point3 getPosCell(size_t i, size_t j) const;
    bool getPosModel(size_t idModel, size_t &i, size_t &j) const noexcept;
    bool checkPosModel(size_t i, size_t j) const noexcept;

    bool intersection(const Ray &ray, intersection_t &intersect) const;

    size_t getCountAllFaces() const noexcept;
    std::ostream& print(std::ostream& os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Scene &scene);


