#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui.moveModelBtn, &QPushButton::clicked, this, &MainWindow::onMoveModelBtn);
}

void MainWindow::onPushButtonClicked() {
    std::cout << "PUSHED" <<std::endl;

    char filename[] = "/home/kathrine/cg_cp/data/test_model_3.txt";
    char filename2[] = "/home/kathrine/cg_cp/data/test_model_4.txt";
    const char *f2 = &(filename2[0]);
    const char *f = &(filename[0]);

    TrianglesModelLoadCommand load_command(f, idMaterial::BLUE);
    facade.execute(load_command);

    TrianglesModelLoadCommand load_command2(f2, idMaterial::RED);
    facade.execute(load_command2);

    QtDrawCommand command(ui.graphicsView);
    facade.execute(command);
}

void MainWindow::onMoveModelBtnClicked() {
    std::cout << "MoveModelBtnClicked" <<std::endl;
}
