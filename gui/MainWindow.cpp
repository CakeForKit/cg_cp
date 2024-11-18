#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);

    graphicsView = new MyQGraphicsView(ui.centralwidget);
    ui.layoutForGraphicsView->addWidget(graphicsView);

    connect(ui.loadModelBtn, &QPushButton::clicked, this, &MainWindow::onLoadModelBtnClicked);
    connect(ui.ChangeMaterialBtn, &QPushButton::clicked, this, &MainWindow::onChangeMaterialBtnClicked);
    connect(ui.drawBtn, &QPushButton::clicked, this, &MainWindow::onDrawBtnClicked);
    // connect(ui.moveModelBtn, &QPushButton::clicked, this, &MainWindow::onMoveModelBtnClicked);
    // connect(ui.rotateModelBtn, &QPushButton::clicked, this, &MainWindow::onRotateModelBtnClicked);
    // connect(ui.rotateOXCameraBtn, &QPushButton::clicked, this, &MainWindow::onRotateOXCameraBtnClicked);
    // connect(ui.rotateOYCameraBtn, &QPushButton::clicked, this, &MainWindow::onRotateOYCameraBtnClicked);

    // загрузка шахматной доски
    char fnB[] = "/home/kathrine/cg_cp/data/chessboard/black_cells_chessboard.txt";
    char fnW[] = "/home/kathrine/cg_cp/data/chessboard/white_cells_chessboard.txt";
    char fnBase[] = "/home/kathrine/cg_cp/data/chessboard/base_chessboard.txt";
    char fnDataCells[] = "/home/kathrine/cg_cp/data/chessboard/positions_cells.txt";
    TrianglesChessboardLoadCommand chessboard_load_command(&(fnB[0]), idMaterial::GLOSSY_BLACK,
                                                            &(fnW[0]), idMaterial::GLOSSY_WHITE,
                                                            &(fnBase[0]), idMaterial::WOOD,
                                                            fnDataCells);
    facade.execute(chessboard_load_command);

    // загрузка данных о фигурах 
    dataMaps.fillModelsComboBox(ui.ModelsComboBox);
    // загрузка позиций
    dataMaps.fill_iPosComboBox(ui.iPosComboBox);
    dataMaps.fill_jPosComboBox(ui.jPosComboBox);
    // загрузка данный о наборах материалов
    dataMaps.fill_MaterialsComboBox(ui.MaterialsPairsComboBox);
    dataMaps.fill_ColorsComboBox(ui.ColorsComboBox);

    onChangeMaterialBtnClicked();
    updateModelsTable();
}

void MainWindow::updateModelsTable() {
    FillModelsTableCommand cmd(ui.TableWidget);
    facade.execute(cmd);
}

void MainWindow::onLoadModelBtnClicked() {
    std::cout << "onLoadModelBtnClicked: ------------" <<std::endl;

    typeChess type = static_cast<typeChess>(ui.ModelsComboBox->currentIndex());
    const char *filename = dataMaps.getFilename(type);
    indPair p = static_cast<indPair>(ui.ColorsComboBox->currentIndex());
    TrianglesModelLoadCommand load_command1(filename, STEP_OF_REVOLVING, p, type);
    facade.execute(load_command1);

    size_t i, j;
    i = static_cast<size_t>(ui.iPosComboBox->currentIndex());
    j = static_cast<size_t>(ui.jPosComboBox->currentIndex());
    MoveCellModelCommand move_cmd(0, i, j);
    facade.execute(move_cmd);

    updateModelsTable();

    // char filename2[] = "/home/kathrine/cg_cp/data/rook.txt";
    // TrianglesModelLoadCommand load_command2(&(filename2[0]), STEP_OF_REVOLVING, idMaterial::MATTE_WHITE);
    // facade.execute(load_command2);
    // MoveCellModelCommand move_cmd2(1, 4, 3);
    // facade.execute(move_cmd2);
    

    // char filename[] = "/home/kathrine/cg_cp/data/chessboard/black_cells_chessboard.txt";
    // TrianglesModelLoadCommand load_command(&(filename[0]), STEP_OF_REVOLVING, idMaterial::GLOSSY_WHITE);
    // facade.execute(load_command);    

    // size_t stepOfRevolving = 6;
    // std::vector<MoveModelCommand> moveCmds;
    // moveCmds.push_back(MoveModelCommand(0, 0, 0, 0));
    // moveCmds.push_back(MoveModelCommand(1, -50, 0, 0));
    // moveCmds.push_back(MoveModelCommand(2, 50, 0, 0));
    // moveCmds.push_back(MoveModelCommand(3, 0, 50, 0));
    // moveCmds.push_back(MoveModelCommand(4, 0, -50, 0));
    // for (size_t i = 0; i < 5; ++i) {
    //     TrianglesModelLoadCommand load_command(&(filename2[0]), stepOfRevolving, idMaterial::RED);
    //     facade.execute(load_command);
    //     facade.execute(moveCmds[i]);
    //     std::cout << "CountAllFaces = " << facade.getCountFacesOnScene() << "\n";
    // }

    std::cout << "endonLoadModelBtnClicked: ---------" <<std::endl;
}

void MainWindow::onChangeMaterialBtnClicked() {
    std::cout << "onChangeMaterialBtnClicked: ------------" <<std::endl;

    idPairMaterial idPair = static_cast<idPairMaterial>(ui.MaterialsPairsComboBox->currentIndex());
    SetActiveMaterialCommand change_material_cmd(idPair);
    facade.execute(change_material_cmd);

    ui.PairMaterialLabel->setText(ui.MaterialsPairsComboBox->currentText());

    updateModelsTable();
    std::cout << "endChangeMaterialBtnClicked: ------------" <<std::endl;
}

void MainWindow::onDrawBtnClicked() {
    std::cout << "onDrawBtnClicked: ------------" <<std::endl;

    QtDrawCommand command(graphicsView);
    facade.execute(command);

    std::cout << "end onDrawBtnClicked: --------" <<std::endl;
}

size_t MainWindow::getSelectedModelId() const {
    int id = 0; // TODO get id from info table

    if (id == -1) {
        time_t curTime = time(NULL);
        throw NoSelectedModelException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return static_cast<size_t>(id);
}

void MainWindow::onMoveModelBtnClicked() {
    std::cout << "MoveModelBtnClicked: ------------" <<std::endl;

    try {
        size_t id = getSelectedModelId();

        // double dx = ui.dx_dsp->value();
        // double dy = ui.dy_dsp->value();
        // double dz = ui.dz_dsp->value();

        MoveModelCommand command(id, 10, 10, 10);
        facade.execute(command);
    } catch (NoSelectedModelException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать модель.");
        return;
    } catch (BaseException &ex) {
        std::cout << ex.what() << "\n";
        exit(EXIT_FAILURE);
    }

    updateModelsTable();
    std::cout << "end MoveModelBtnClicked ---------" <<std::endl;

    onDrawBtnClicked();
}

void MainWindow::onRotateModelBtnClicked() {
    std::cout << "RotateModelBtnClicked: ------------" <<std::endl;

    try {
        size_t id = getSelectedModelId();

        float angle_grad = static_cast<float>(30);

        RotateModelCommand command(id, angle_grad);
        facade.execute(command);
    } catch (NoSelectedModelException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать модель.");
        return;
    } catch (BaseException &ex) {
        std::cout << ex.what() << "\n";
        exit(EXIT_FAILURE);
    }

    updateModelsTable();
    std::cout << "end RotateModelBtnClicked ---------" <<std::endl;

    onDrawBtnClicked();
}

void MainWindow::rotateCamera(Axis axis) {
    try {
        float angle_grad = static_cast<float>(30);

        RotateCameraCommand command(angle_grad, axis);
        facade.execute(command);
    } catch (BaseException &ex) {
        std::cout << ex.what() << "\n";
        exit(EXIT_FAILURE);
    }
}

void MainWindow::onRotateOXCameraBtnClicked() {
    std::cout << "onRotateOXCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OX);
    std::cout << "end onRotateOXCameraBtnClicked ---------" <<std::endl;

    onDrawBtnClicked();
}

void MainWindow::onRotateOYCameraBtnClicked() {
    std::cout << "onRotateOYCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OY);
    std::cout << "end onRotateOYCameraBtnClicked ---------" <<std::endl;

    onDrawBtnClicked();
}

void MainWindow::measureRenderTime() {
    char filename[] = "/home/kathrine/cg_cp/data/pawn.txt";
    char datafilename[] = "../data_time/dataTime.txt";

    size_t stepOfRevolving = 6;
    std::vector<MoveModelCommand> moveCmds;
    moveCmds.push_back(MoveModelCommand(0, 0, 0, 0));
    moveCmds.push_back(MoveModelCommand(1, -50, 0, 0));
    moveCmds.push_back(MoveModelCommand(2, 50, 0, 0));
    moveCmds.push_back(MoveModelCommand(3, 0, 50, 0));
    moveCmds.push_back(MoveModelCommand(4, 0, -50, 0));
    for (size_t i = 0; i < 5; ++i) {
        TrianglesModelLoadCommand load_command(&(filename[0]), stepOfRevolving, indPair::WHITE, typeChess::PAWN);
        facade.execute(load_command);
        facade.execute(moveCmds[i]);
        std::cout << "CountAllFaces = " << facade.getCountFacesOnScene() << "\n";
        std::ofstream f(datafilename, std::ios::app);
        if (f.is_open()) {
            f << facade.getCountFacesOnScene() << "\t";
        } else 
            std::cout << "Error: " << strerror(errno) << "\n";
        f.close(); 
        DrawTimeCommand time_draw_command(graphicsView, &(datafilename[0]));
        facade.execute(time_draw_command);
    }
    
    exit(EXIT_SUCCESS);
}