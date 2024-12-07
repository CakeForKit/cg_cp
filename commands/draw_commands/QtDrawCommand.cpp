#include "QtDrawCommand.h"

// QtDrawCommand::QtDrawCommand(QGraphicsView* gv) 
// : graphicsView(gv), part(0) {}

QtDrawCommand::QtDrawCommand(std::shared_ptr<QImage> qimg) 
: img(qimg) {
    // img = qimg;
    std::cout << "size: " << qimg->width() << " " << qimg->height() << "\n";

}
    
void QtDrawCommand::execute() {
    std::cout << "QtDrawCommand::execute 0\n";
    std::shared_ptr<QtDrawer> drawer = std::make_shared<QtDrawer>(img);
    std::shared_ptr<Scene> scene = sceneManager->getScene();
    std::shared_ptr<Camera> camera = scene->getActiveCamera();
    std::cout << "QtDrawCommand::execute 1\n";
    drawManager->drawScene(scene, camera, drawer);
    std::cout << "QtDrawCommand::execute 2\n";
    // if (part == 0) {
    //     drawer = std::make_shared<QtDrawer>(graphicsView);
    //     part += 1;
    // } else if (part == 1) {
    //     std::shared_ptr<Scene> scene = sceneManager->getScene();
    //     std::shared_ptr<Camera> camera = scene->getActiveCamera();
    //     drawManager->drawScene(scene, camera, drawer);
    //     part += 1;
    // } else {
    //     drawer->setScene();
    //     part += 1;
    // }
    
}