#include "FillModelsTableCommand.h"


FillModelsTableCommand::FillModelsTableCommand(QTableWidget *_tab) 
: tab(_tab) {}

void FillModelsTableCommand::execute() {
    sceneManager->writeDataToTable(tab);
}