#pragma once

#include "DrawManager.h"
#include "SceneManager.h"
#include "LoadManager.h"

class BaseCommand 
{
protected:
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<SceneManager> sceneManager;
    std::shared_ptr<LoadManager> loadManager;

public:
    virtual ~BaseCommand() = default;

    void setManagers(std::shared_ptr<DrawManager> _drawManager, 
                    std::shared_ptr<SceneManager> _sceneManager, 
                    std::shared_ptr<LoadManager> _loadManager) noexcept;
    virtual void execute() = 0;
};
