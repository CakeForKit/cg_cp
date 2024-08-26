#pragma once

#include "ObjectScene.h"
#include "Camera.h"

class Scene
{
protected:
    std::vector<std::shared_ptr<ObjectScene>> models;
    std::vector<std::shared_ptr<Camera>> cameras;

public:
    Scene();

    void addCamera() noexcept;
    void removeCamera(size_t ind);
    std::shared_ptr<Camera> getCamera(size_t ind) const;

    std::ostream& print(std::ostream& os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Scene &scene);


