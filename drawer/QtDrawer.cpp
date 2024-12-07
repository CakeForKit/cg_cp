#include "QtDrawer.h"


// QtDrawer::QtDrawer(QGraphicsView* canv)
// : canvas(canv) {
//     std::cout << "QtDrawer() 1\n";
//     int img_width = canvas->viewport()->width();
//     std::cout << "QtDrawer() 2\n";
//     int img_height = canvas->viewport()->height();
//     img = QImage(img_width, img_height, QImage::Format_RGB32);
//     std::cout << "QtDrawer() 3\n";
//     scene = new QGraphicsScene();
// }

QtDrawer::QtDrawer(std::shared_ptr<QImage> qimg) 
: img(qimg) {
    // img = qimg;
    // int img_width = canvas->viewport()->width();
    // int img_height = canvas->viewport()->height();
    // img = QImage(img_width, img_height, QImage::Format_RGB32);
    // scene = new QGraphicsScene();
}


int QtDrawer::getImgWidth() {return img->width(); } // { return canvas->viewport()->width(); }

int QtDrawer::getImgHeight() {return img->height(); } // { return canvas->viewport()->height(); }

void QtDrawer::setPixelColor(int x, int y, const Color &color) {
    img->setPixelColor(x, y, color.getQColor());
}

void QtDrawer::setPixelColor(int x, int y, const Color &&color) {
    img->setPixelColor(x, y, color.getQColor());
}

// void QtDrawer::setScene() {
//     // QGraphicsScene* scene = new QGraphicsScene();
//     scene->addPixmap(QPixmap::fromImage(img));
//     canvas->setScene(scene);
// }
