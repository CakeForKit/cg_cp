#include "BaseCommand.h"


void BaseCommand::setManagers(std::shared_ptr<DrawManager> _drawManager, 
                                std::shared_ptr<SceneManager> _sceneManager) noexcept{
    drawManager = _drawManager;
    sceneManager = _sceneManager;
}