#pragma once

#include "BaseCommand.h"
#include "QtDrawer.h"
#include <QGraphicsView>

class DrawTimeCommand : public BaseCommand
{
protected:
    QGraphicsView *graphicsView;

public:
    DrawTimeCommand() = delete;
    DrawTimeCommand(QGraphicsView* gv);
    
    virtual void execute();
};