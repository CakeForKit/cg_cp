#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);
    
    // TODO Material manager
    materialSolution.registrate(idMaterial::RED, std::make_shared<Material>(Intensity(0.1, 0, 0), 
                                                                            Intensity(0.5, 0, 0), 
                                                                            Intensity(0.2, 0, 0),
                                                                            50));
    materialSolution.registrate(idMaterial::BLUE, std::make_shared<Material>(Intensity(0.157, 0.3, 0.34), 
                                                                            Intensity(0.213, 0.5, 0.56), 
                                                                            Intensity(0.05, 0.05, 0.05),
                                                                            5));

    connect(ui.pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

void MainWindow::onPushButtonClicked() {
    std::cout << "PUSHED" <<std::endl;

    char filename[] = "/home/kathrine/cg_cp/data/test_model_3.txt";
    const char *f = &(filename[0]);

    TrianglesModelLoadCommand load_command(f, materialSolution.getMaterial(idMaterial::BLUE));
    facade.execute(load_command);

    QtDrawCommand command(ui.graphicsView);
    facade.execute(command);
}
