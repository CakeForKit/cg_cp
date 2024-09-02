#include "BaseCommand.h"


void BaseCommand::setManagers(std::shared_ptr<DrawManager> _drawManager, 
                                std::shared_ptr<SceneManager> _sceneManager, 
                                std::shared_ptr<LoadManager> _loadManager) noexcept{
    drawManager = _drawManager;
    sceneManager = _sceneManager;
    loadManager = _loadManager;
}