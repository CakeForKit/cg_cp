#include "DrawTimeCommand.h"

DrawTimeCommand::DrawTimeCommand(QGraphicsView* gv) 
: graphicsView(gv) {}
    
void DrawTimeCommand::execute() {
    std::shared_ptr<Drawer> drawer = std::make_shared<QtDrawer>(graphicsView);
    
    std::shared_ptr<Scene> scene = sceneManager->getScene();
    std::shared_ptr<Camera> camera = scene->getActiveCamera();

    char filename[] = "../data_time/dataTime.txt";
    drawManager->collectTimeDataDrawScene(&(filename[0]), scene, camera, drawer);
}