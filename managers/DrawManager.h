#pragma once

#include "StandardRayTracing.h"

class DrawManager
{
protected:
    // TODO solution, change_alg(), index_in_config
public:
    // DrawManager();
    void drawScene(std::shared_ptr<Scene> scene, size_t indexCamera, std::shared_ptr<Drawer> drawer);
};
