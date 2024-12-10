#include "ClearSceneCommand.h"


ClearSceneCommand::ClearSceneCommand() {}

void ClearSceneCommand::execute() {
    sceneManager->clearScene();
}