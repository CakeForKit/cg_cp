#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

void MainWindow::onPushButtonClicked() {
    std::cout << "PUSHED" <<std::endl;

    QtDrawCommand command(ui.graphicsView);
    facade.execute(command);
}
