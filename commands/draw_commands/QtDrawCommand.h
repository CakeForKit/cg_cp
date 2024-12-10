#pragma once

#include "BaseDrawCommand.h"
#include "QtDrawer.h"
#include <QGraphicsView>

class QtDrawCommand : public BaseDrawCommand
{
protected:
    std::shared_ptr<QImage> img;

public:
    QtDrawCommand() = delete;
    QtDrawCommand(std::shared_ptr<QImage> qimg);
    
    virtual void execute();
};