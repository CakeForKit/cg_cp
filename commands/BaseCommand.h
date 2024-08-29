#pragma once

#include "DrawManager.h"
#include "SceneManager.h"

class BaseCommand 
{
protected:
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<SceneManager> sceneManager;

public:
    virtual ~BaseCommand() = default;

    void setManagers(std::shared_ptr<DrawManager> _drawManager, std::shared_ptr<SceneManager> _sceneManager) noexcept;
    virtual void execute() = 0;
};
