#pragma once

#include "BaseCommand.h"

class FillModelsTableCommand : public BaseCommand 
{
protected:
    QTableWidget *tab;

public:
    FillModelsTableCommand(QTableWidget *_tab);

    virtual void execute();
};