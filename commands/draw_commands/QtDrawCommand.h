#pragma once

#include "BaseDrawCommand.h"
#include "QtDrawer.h"
#include <QGraphicsView>

class QtDrawCommand : public BaseDrawCommand
{
protected:
    std::shared_ptr<QImage> img;
    // QGraphicsView *graphicsView;
    // std::shared_ptr<QtDrawer> drawer;
    // int part;

public:
    QtDrawCommand() = delete;
    QtDrawCommand(std::shared_ptr<QImage> qimg);
    // QtDrawCommand(QGraphicsView* gv);
    
    // надо выполнить 3 раза
    virtual void execute();
};