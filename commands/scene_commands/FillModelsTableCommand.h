#pragma once

#include "BaseCommand.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QObject>
#include <QLabel>
#include <QSize>
#include <QHBoxLayout>

class FillModelsTableCommand : public BaseCommand 
{
protected:
    QTableWidget *tab;

public:
    FillModelsTableCommand(QTableWidget *_tab);

    virtual void execute();
};