#include "FillModelsTableCommand.h"


FillModelsTableCommand::FillModelsTableCommand(QTableWidget *_tab) 
: tab(_tab) {}

void FillModelsTableCommand::execute() {
    // sceneManager->writeDataToTable(tab);
    QStringList header = {"id", "Фигура", "Цвет", "Позиция"};
    tab->setHorizontalHeaderLabels(header);

    tab->setRowCount(static_cast<int>(sceneManager->countModels()));
    tab->setColumnCount(static_cast<int>(header.size()));

    PtrModel m;
    char id[5], pos[3];
    pos[2] = 0;
    int ii = 0;
    size_t pi, pj;
    for (size_t i = 0; i < sceneManager->countModels(); ++i, ++ii) {
        m = sceneManager->getModel(i);

        sprintf(id, "%ld", i + 1);
        tab->setItem(ii, 0, new QTableWidgetItem(id));
        tab->setItem(ii, 1, new QTableWidgetItem(mapNamesChess[m->getTypeChess()]));

        QPixmap myPixmap(20, 30);
        QWidget *pWidget = new QWidget();
        QHBoxLayout *pLayout = new QHBoxLayout(pWidget);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0,0,0,0);
        QLabel *label = new QLabel;
        label->setMaximumSize(QSize(100, 20));
        label->setScaledContents(true);
        myPixmap.fill(m->getColor().getQColor());
        label->setPixmap(myPixmap);
        pLayout->addWidget(label);
        pWidget->setLayout(pLayout);
        tab->setCellWidget(ii, 2, pWidget);
        
        // std::cout << "FillModelsTableCommand: see i = " << i << "\n";
        assert(sceneManager->getPosModel(i, pi, pj));
        pos[0] = static_cast<char>(97 + pj);
        pos[1] = static_cast<char>(49 + pi);
        
        tab->setItem(ii, 3, new QTableWidgetItem(pos));
    }
}