#pragma once

#include "BaseCommand.h"

class FacadeScene
{
private:
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<SceneManager> sceneManager;
    std::shared_ptr<LoadManager> loadManager;

public:
    
    FacadeScene();

    void execute(BaseCommand &cmd);
};
