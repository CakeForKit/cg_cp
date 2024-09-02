#include "FacadeScene.h"


FacadeScene::FacadeScene() {
    drawManager = std::make_shared<DrawManager>();
    sceneManager = std::make_shared<SceneManager>();
    loadManager = std::make_shared<LoadManager>();

}

void FacadeScene::execute(BaseCommand &cmd) {
    cmd.setManagers(drawManager, sceneManager, loadManager);
    cmd.execute();
}