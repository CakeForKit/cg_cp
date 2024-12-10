#include "QtDrawCommand.h"


QtDrawCommand::QtDrawCommand(std::shared_ptr<QImage> qimg) 
: img(qimg) {}
    
void QtDrawCommand::execute() {
    std::shared_ptr<QtDrawer> drawer = std::make_shared<QtDrawer>(img);
    std::shared_ptr<Scene> scene = sceneManager->getScene();
    std::shared_ptr<Camera> camera = scene->getActiveCamera();
    std::cout << "Count faces on scene: " << scene->getCountAllFaces() << "\n";

    drawManager->drawScene(scene, camera, drawer);
}