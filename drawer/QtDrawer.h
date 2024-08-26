#pragma once

#include <QGraphicsView>
#include <QImage>
#include <memory>

#include "Drawer.h"

class QtDrawer : public Drawer
{
protected:
    QGraphicsView* canvas;
    QImage img;

public:
    QtDrawer(QGraphicsView* canv);

    virtual int getImgWidth();
    virtual int getImgHeight();

    virtual void setPixelColor(int x, int y, const Color &color);
    virtual void setScene();
};
