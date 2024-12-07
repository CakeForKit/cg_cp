#include "DrawTimeCommand.h"

DrawTimeCommand::DrawTimeCommand(std::shared_ptr<QImage> qimg, char *_filename) 
: img(qimg), filename(_filename){}
    
void DrawTimeCommand::execute() {
    // std::shared_ptr<Drawer> drawer = std::make_shared<QtDrawer>(graphicsView);
    std::shared_ptr<QtDrawer> drawer = std::make_shared<QtDrawer>(img);
    
    std::shared_ptr<Scene> scene = sceneManager->getScene();
    std::shared_ptr<Camera> camera = scene->getActiveCamera();

    drawManager->collectTimeDataDrawScene(&(filename[0]), scene, camera, drawer);
}