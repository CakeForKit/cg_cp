#include "MainWindow.h"

#pragma region MainWindow()
MainWindow::MainWindow(QWidget *parant) : QMainWindow(parant), facade(FacadeScene()) {
    ui.setupUi(this);

    graphicsView = new MyQGraphicsView(ui.centralwidget);
    ui.layoutForGraphicsView->addWidget(graphicsView);

    connect(ui.loadModelBtn, &QPushButton::clicked, this, &MainWindow::onLoadModelBtnClicked);
    connect(ui.ChangeMaterialBtn, &QPushButton::clicked, this, &MainWindow::onChangeMaterialBtnClicked);
    connect(ui.drawBtn, &QPushButton::clicked, this, &MainWindow::onDrawBtnClicked);
    connect(ui.MoveModelBtn, &QPushButton::clicked, this, &MainWindow::onMoveModelBtnClicked);
    connect(ui.RotateModelBtn, &QPushButton::clicked, this, &MainWindow::onRotateModelBtnClicked);
    connect(ui.DelModelBtn, &QPushButton::clicked, this, &MainWindow::onDelModelBtnClicked);
    connect(ui.UpCameraBtn, &QPushButton::clicked, this, &MainWindow::onUpCameraBtnClicked);
    connect(ui.DownCameraBtn, &QPushButton::clicked, this, &MainWindow::onDownCameraBtnClicked);
    connect(ui.RightCameraBtn, &QPushButton::clicked, this, &MainWindow::onRightCameraBtnClicked);
    connect(ui.LeftCameraBtn, &QPushButton::clicked, this, &MainWindow::onLeftCameraBtnClicked);
    connect(ui.ZoomCameraBtn, &QPushButton::clicked, this, &MainWindow::onZoomCameraBtnClicked);
    connect(ui.MoveAwayCameraBtn, &QPushButton::clicked, this, &MainWindow::onMoveAwayCameraBtnClicked);
    connect(ui.TableWidget, &QTableWidget::cellActivated, this, &MainWindow::tableCellActivated);
    connect(ui.GlossyRadioBtn, &QRadioButton::toggled, this, &MainWindow::toggledGlossyRadioBtn);
    connect(ui.MatteRadioBtn, &QRadioButton::toggled, this, &MainWindow::toggledMatteRadioBtn);
    connect(ui.exitMenu, &QMenu::aboutToShow, this, &MainWindow::exitMenuTriggered);
    connect(this, &MainWindow::EndRenderSignal, this, &MainWindow::EndRenderSlot);

    // загрузка шахматной доски
    char fnB[] = "/home/kathrine/cg_cp/data/chessboard/black_cells_chessboard.txt";
    char fnW[] = "/home/kathrine/cg_cp/data/chessboard/white_cells_chessboard.txt";
    char fnBase[] = "/home/kathrine/cg_cp/data/chessboard/base_chessboard.txt";
    char fnDataCells[] = "/home/kathrine/cg_cp/data/chessboard/positions_cells.txt";
    TrianglesChessboardLoadCommand chessboard_load_command(&(fnB[0]), // idMaterial::GLOSSY_BLACK,
                                                            &(fnW[0]), // idMaterial::GLOSSY_WHITE,
                                                            &(fnBase[0]), idMaterial::WOOD,
                                                            fnDataCells);
    facade.execute(chessboard_load_command);

    // загрузка данных о фигурах 
    dataMaps.fillModelsComboBox(ui.ModelsComboBox);
    // загрузка позиций
    dataMaps.fill_iPosComboBox(ui.iPosComboBox);
    dataMaps.fill_jPosComboBox(ui.jPosComboBox);
    dataMaps.fill_iPosComboBox(ui.MoveTo_iPosComboBox);
    dataMaps.fill_jPosComboBox(ui.MoveTo_jPosComboBox);
    // загрузка данный о наборах материалов
    dataMaps.fill_MaterialsComboBox(ui.MaterialsPairsComboBox);
    dataMaps.fill_ColorsComboBox(ui.ColorsComboBox);

    // ui.TableWidget->horizontalHeader()->setStretchLastSection(true);
    ui.TableWidget->resizeColumnsToContents();

    // выделение памяти под поток рендеринга
    threadRender = static_cast<pthread_t*>(malloc(sizeof(pthread_t)));
    assert(threadRender != NULL);
    dataThr = static_cast<ThrData*>(malloc(sizeof(ThrData)));
    assert(dataThr != NULL);

    onChangeMaterialBtnClicked();
    updateModelsTable();

    RotateCameraCommand command(-30, Axis::OX);
    facade.execute(command);
}

MainWindow::~MainWindow() {
    free(threadRender);
    free(dataThr);
}

void MainWindow::InformationBusy() {
    QMessageBox::information(nullptr, "Пожалуйста подождите", 
    "В данный момент производится рендеринг изображения и никакие параметры менять нельзя");
}

#pragma region updateModelsTable
void MainWindow::updateModelsTable() {
    FillModelsTableCommand cmd(ui.TableWidget);
    facade.execute(cmd);
    ui.TableWidget->resizeColumnsToContents();

    ui.AllModelsComboBox->clear();
    int cntRows = ui.TableWidget->rowCount();
    char id[2];
    id[1] = 0;
    for (int i = 0; i < cntRows; ++i) {
        id[0] = static_cast<char>(49 + i);
        ui.AllModelsComboBox->insertItem(i + 1, id);
    }
}

void MainWindow::tableCellActivated(int row, int column) {
    (void) column;
    ui.AllModelsComboBox->setCurrentIndex(row);
    // std::cout << "tableCellActivated " << ui.TableWidget->currentRow() << "\n\n\n";
}

#pragma region Load
void MainWindow::onLoadModelBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onLoadModelBtnClicked: ------------" <<std::endl;

    try {
        size_t i, j;
        i = static_cast<size_t>(ui.iPosComboBox->currentIndex());
        j = static_cast<size_t>(ui.jPosComboBox->currentIndex());

        typeChess type = static_cast<typeChess>(ui.ModelsComboBox->currentIndex());
        const char *filename = dataMaps.getFilename(type);
        indPair p = static_cast<indPair>(ui.ColorsComboBox->currentIndex());
        TrianglesModelLoadCommand load_command1(filename, STEP_OF_REVOLVING, p, type, i, j);
        facade.execute(load_command1);

        updateModelsTable();
    } catch (ReadException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка в файлах с данными для загрузки фигур");
        std::cout << ex.what() << "\n";
        return;
    } catch (NoPlaceSceneException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "Нельзя добавить больше фигур на сцену");
        std::cout << ex.what() << "\n";
        return;
    } catch (BusyPosSceneException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "На данной позиции уже есть фигура");
        std::cout << ex.what() << "\n";
        return;
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
    std::cout << "endonLoadModelBtnClicked: ---------" <<std::endl;
}

#pragma region Change Material
void MainWindow::onChangeMaterialBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onChangeMaterialBtnClicked: ------------" <<std::endl;

    try {
        idPairMaterial idPair = static_cast<idPairMaterial>(ui.MaterialsPairsComboBox->currentIndex());
        SetActiveMaterialCommand change_material_cmd(idPair);
        facade.execute(change_material_cmd);

        ui.PairMaterialLabel->setText(ui.MaterialsPairsComboBox->currentText());

        updateModelsTable();
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
    
    std::cout << "endChangeMaterialBtnClicked: ------------" <<std::endl;
}


#pragma region Draw
static void *thfunc(void *arg) {
    std::cout << "Thread render\n";
    ThrData* dataThr = static_cast<ThrData*>(arg);

    QtDrawCommand command(dataThr->img);
    dataThr->pfacade->execute(command);

    emit dataThr->mwindow->EndRenderSignal(dataThr->img);
    pthread_exit(EXIT_SUCCESS);
}

void MainWindow::onDrawBtnClicked() {
    std::cout << "onDrawBtnClicked: ------------" <<std::endl;

    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    status = StatusGui::BUSY_RENDER;
    ui.MatteRadioBtn->setEnabled(false);
    ui.GlossyRadioBtn->setEnabled(false);

    try {
        int img_width = graphicsView->viewport()->width();
        int img_height = graphicsView->viewport()->height();
        std::shared_ptr<QImage> img = std::make_shared<QImage>(img_width, img_height, QImage::Format_RGB32);
        std::cout << "image size: " << img->width() << "x" << img->height() << "\n";

        dataThr->pfacade = &facade;
        dataThr->mwindow = this;
        dataThr->img = img;

        int rc = pthread_create(threadRender, NULL, thfunc, dataThr);
        assert(rc == 0);
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
}

void MainWindow::EndRenderSlot(std::shared_ptr<QImage> img) {
    try {
        QGraphicsScene* scene = new QGraphicsScene();
        scene->addPixmap(QPixmap::fromImage(*img));
        graphicsView->setScene(scene);

        saveToFile();
        std::cout << "end onDrawBtnClicked: --------" <<std::endl;
        status = StatusGui::FREE;
        ui.MatteRadioBtn->setEnabled(true);
        ui.GlossyRadioBtn->setEnabled(true);
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
}

#pragma region Transform
void MainWindow::onMoveModelBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "MoveModelBtnClicked: ------------" <<std::endl;

    try {
        size_t id, pi, pj;
        id = static_cast<size_t>(ui.AllModelsComboBox->currentIndex());
        pi = static_cast<size_t>(ui.MoveTo_iPosComboBox->currentIndex());
        pj = static_cast<size_t>(ui.MoveTo_jPosComboBox->currentIndex());
        std::cout << "onMoveModelBtnClicked: " << pi << " " << pj << "\n";
        MoveCellModelCommand command(id, pi, pj);
        facade.execute(command);
    } catch (BusyPosSceneException &ex) {
        QMessageBox::critical(nullptr, "Ошибка", "На данной позиции уже есть фигура");
        std::cout << ex.what() << "\n";
        return;
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }

    updateModelsTable();
    std::cout << "end MoveModelBtnClicked ---------" <<std::endl;
}

void MainWindow::onRotateModelBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "RotateModelBtnClicked: ------------" <<std::endl;

    try {
        size_t id = static_cast<size_t>(ui.AllModelsComboBox->currentIndex());
        float angle_grad = static_cast<float>(ui.AngleModelDSP->value());
        RotateModelCommand command(id, angle_grad);
        facade.execute(command);

        updateModelsTable();

    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
    std::cout << "end RotateModelBtnClicked ---------" <<std::endl;
}

void MainWindow::onDelModelBtnClicked() {
    try {
        if (status == StatusGui::BUSY_RENDER) {
            InformationBusy();
            return;
        }
        std::cout << "onDelModelBtnClicked: ------------" <<std::endl;
    
        size_t id = static_cast<size_t>(ui.AllModelsComboBox->currentIndex());

        RemoveModelCommand command(id);
        facade.execute(command);
        
        updateModelsTable();

    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
    std::cout << "end DelModelBtnClicked: ------------" <<std::endl;
}

#pragma region Chessboard
void MainWindow::toggledGlossyRadioBtn(bool checked) {
    try {
        if (checked) {
            std::cout << "toggledGlossyRadioBtn\n";

            SetChessboardMaterialCommand cmd(idChessboardMaterial::GLOSSY);
            facade.execute(cmd);
        }
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }   
}

void MainWindow::toggledMatteRadioBtn(bool checked) {
    try {
        if (checked) {
            std::cout << "toggledMatteRadioBtn\n";

            SetChessboardMaterialCommand cmd(idChessboardMaterial::MATTE);
            facade.execute(cmd);
        }
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    } 
    
}
#pragma region end

#pragma region Camera
void MainWindow::rotateCamera(Axis axis, int sign) {
    try {
        float angle_grad = static_cast<float>(ui.AngleCameraDSB->value());
        if (sign < 0)
            angle_grad *= -1;
        std::cout << "rotateCamera: angle = " << angle_grad << "\n";
        RotateCameraCommand command(angle_grad, axis);
        facade.execute(command);
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
}

void MainWindow::onUpCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onUpCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OX, -1);
    std::cout << "end onUpCameraBtnClicked ---------" <<std::endl;
}

void MainWindow::onDownCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onDownCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OX, 1);
    std::cout << "end onDownCameraBtnClicked ---------" <<std::endl;
}

void MainWindow::onRightCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onRightCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OY, 1);
    std::cout << "end onRightCameraBtnClicked ---------" <<std::endl;
}

void MainWindow::onLeftCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onLeftCameraBtnClicked: ------------" <<std::endl;
    rotateCamera(Axis::OY, -1);
    std::cout << "end onLeftCameraBtnClicked ---------" <<std::endl;
}

void MainWindow::moveCamera(int sign) {
    try {
        double length = ui.MoveCameraDSP->value();
        if (sign < 0)
            length *= -1;

        MoveCameraCommand command(length);
        facade.execute(command);
    } catch (TooCloseCameraException &ex) {
        QMessageBox::critical(nullptr, "Камера слишком близко", 
        "Не рекомендуется приближать камеру так близко, так как в таком случае вы можете не увидеть картинку целиком");
        std::cout << ex.what() << "\n";
        return;
    } catch (BaseException &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
}

void MainWindow::onZoomCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onZoomCameraBtnClicked: ------------" <<std::endl;
    moveCamera(1);
    std::cout << "end onZoomCameraBtnClicked ---------" <<std::endl;
}

void MainWindow::onMoveAwayCameraBtnClicked() {
    if (status == StatusGui::BUSY_RENDER) {
        InformationBusy();
        return;
    }
    std::cout << "onMoveAwayCameraBtnClicked: ------------" <<std::endl;
    moveCamera(-1);
    std::cout << "end onMoveAwayCameraBtnClicked ---------" <<std::endl;
}

#pragma region saveToFile

void MainWindow::saveToFile() {
    try {
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y_%H:%M:%S",timeinfo);
        std::string filename(buffer);
        filename = "/home/kathrine/cg_cp/saved_img/" + filename + ".png";

        QPixmap pixMap = graphicsView->grab(graphicsView->sceneRect().toRect());
        pixMap.save(filename.c_str());
    } catch (std::exception &ex) {
        QMessageBox::critical(nullptr, "ERROR", ex.what());
        std::cout << ex.what() << "\n";
        return;
    }
        
}

void MainWindow::exitMenuTriggered() {
    this->close();
}

#pragma region Measure Time
void MainWindow::measureRenderTime() {
    char filename[] = "/home/kathrine/cg_cp/data/pawn.txt";
    char datafilename[] = "../data_time/dataTime.txt";

    int img_width = graphicsView->viewport()->width();
    int img_height = graphicsView->viewport()->height();
    std::shared_ptr<QImage> img = std::make_shared<QImage>(img_width, img_height, QImage::Format_RGB32);

    size_t pi = 0, pj = 0;
    size_t stepOfRevolving = 6;
    std::vector<MoveModelCommand> moveCmds;
    moveCmds.push_back(MoveModelCommand(0, 0, 0, 0));
    moveCmds.push_back(MoveModelCommand(1, -50, 0, 0));
    moveCmds.push_back(MoveModelCommand(2, 50, 0, 0));
    moveCmds.push_back(MoveModelCommand(3, 0, 50, 0));
    moveCmds.push_back(MoveModelCommand(4, 0, -50, 0));
    for (size_t i = 0; i < 5; ++i) {
        TrianglesModelLoadCommand load_command(&(filename[0]), stepOfRevolving, indPair::WHITE, typeChess::PAWN, pi, pj++);
        facade.execute(load_command);
        facade.execute(moveCmds[i]);
        std::cout << "CountAllFaces = " << facade.getCountFacesOnScene() << "\n";
        std::ofstream f(datafilename, std::ios::app);
        if (f.is_open()) {
            f << facade.getCountFacesOnScene() << "\t";
        } else 
            std::cout << "Error: " << strerror(errno) << "\n";
        f.close(); 
        DrawTimeCommand time_draw_command(img, &(datafilename[0]));
        facade.execute(time_draw_command);
    }
    
    this->close();
}

