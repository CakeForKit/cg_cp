#pragma once

#include "ObjectScene.h"
#include "Camera.h"

class Scene
{
protected:
    std::vector<std::shared_ptr<ObjectScene>> models;
    std::vector<std::shared_ptr<Camera>> cameras;
    std::shared_ptr<Camera> activeCamera; // указатель на камеру через которую сейчас смотрим. Один из элементов cameras

public:
    Scene();

    void addModel(std::shared_ptr<ObjectScene> model) noexcept;
    void removeModel(size_t ind);
    std::shared_ptr<ObjectScene> getModel(size_t ind);

    void addCamera() noexcept;
    void removeCamera(size_t ind);
    std::shared_ptr<Camera> getCamera(size_t ind);
    void setActiveCamera(size_t ind);
    std::shared_ptr<Camera> getActiveCamera() noexcept;

    bool intersection(const Ray &ray, intersection_t &intersect) const;

    // TODO clearScene()

    std::ostream& print(std::ostream& os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Scene &scene);


