#pragma once

#include "RayTracing.h"

class StandardRayTracing : public RayTracing
{
public:
    StandardRayTracing(std::shared_ptr<Scene> _scene, std::shared_ptr<Camera> _camera, std::shared_ptr<Drawer> _drawer);

    virtual void render();

protected:
    virtual Intensity castRay(Ray &ray, const int depth = 0) const noexcept;
};
