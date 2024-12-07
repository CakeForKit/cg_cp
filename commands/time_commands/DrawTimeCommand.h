#pragma once

#include "BaseCommand.h"
#include "QtDrawer.h"
#include <QGraphicsView>

class DrawTimeCommand : public BaseCommand
{
protected:
    std::shared_ptr<QImage> img;
    char *filename;

public:
    DrawTimeCommand() = delete;
    // DrawTimeCommand(QGraphicsView* gv, char *_filename);
    DrawTimeCommand(std::shared_ptr<QImage> qimg, char *_filename);
    
    virtual void execute();
};