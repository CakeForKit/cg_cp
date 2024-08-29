#pragma once

#include "QtDrawCommand.h"

class FacadeScene
{
private:
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<SceneManager> sceneManager;

public:
    
    FacadeScene();

    void execute(BaseCommand &cmd);
};
