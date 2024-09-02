#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

void MainWindow::onPushButtonClicked() {
    std::cout << "PUSHED" <<std::endl;

    char filename[] = "/home/kathrine/cg_cp/data/test_model_2.txt";
    const char *f = &(filename[0]);

    TrianglesModelLoadCommand load_command(f);
    facade.execute(load_command);

    QtDrawCommand command(ui.graphicsView);
    facade.execute(command);
}
