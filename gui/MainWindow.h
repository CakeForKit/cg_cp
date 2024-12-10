#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QMouseEvent>
#include <QComboBox>
#include <QRadioButton>
#include "ui_mainWindow.h"
#include "FacadeScene.h"
#include "QtDrawCommand.h"
#include "TrianglesModelLoadCommand.h"
#include "TrianglesChessboardLoadCommand.h"
#include "MoveModelCommand.h"
#include "MoveCellModelCommand.h"
#include "RotateModelCommand.h"
#include "RotateCameraCommand.h"
#include "MaterialSolution.h"
#include "DrawTimeCommand.h"
#include "SetActiveMaterialCommand.h"
#include "FillModelsTableCommand.h"
#include "RemoveModelCommand.h"
#include "MoveCameraCommand.h"
#include "SetChessboardMaterialCommand.h"
#include "BeginSceneLoadCommand.h"
#include "AllByOneSceneLoadCommand.h"
#include "TestSceneLoadCommand.h"
#include "ClearSceneCommand.h"
#include "dataMaps.h"

class MainWindow;

class MyQGraphicsView : public QGraphicsView
{
public:
    MyQGraphicsView(QWidget *parent = nullptr) : QGraphicsView(parent) {setMouseTracking(true);}

protected:
    void mousePressEvent(QMouseEvent  *event) override {
        std::cout << "MousePressEvent of MyQGraphicsView: ";

        // int width = viewport()->width();
        // int height = viewport()->height();
        // std::cout << width << "x" << height << "\n";
        QPoint pos = event->pos();
        std::cout << "( " << pos.x() << "," << pos.y() << ")\n";

        QGraphicsView::mousePressEvent(event); // Call base class implementation
    }
};

struct ThrData {
    FacadeScene* pfacade;
    MainWindow* mwindow;
    std::shared_ptr<QImage> img;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow ui;
    MyQGraphicsView *graphicsView;
    FacadeScene facade;
    DataMaps dataMaps;
    pthread_t* threadRender;
    ThrData* dataThr;

    enum StatusGui {
        BUSY_RENDER,
        FREE
    };
    StatusGui status = StatusGui::FREE;

public:
    explicit MainWindow(QWidget *parant = nullptr);
    ~MainWindow();
    void measureRenderTime();

signals:
    // void StartRender();
    void EndRenderSignal(std::shared_ptr<QImage> img);

private slots:
    void InformationBusy();
    void EndRenderSlot(std::shared_ptr<QImage> img);

    void onLoadModelBtnClicked();
    void onChangeMaterialBtnClicked();
    void onDrawBtnClicked();
    void onMoveModelBtnClicked();
    void onRotateModelBtnClicked();
    void onDelModelBtnClicked();
    void onUpCameraBtnClicked();
    void onDownCameraBtnClicked();
    void onRightCameraBtnClicked();
    void onLeftCameraBtnClicked();
    void onZoomCameraBtnClicked();
    void onMoveAwayCameraBtnClicked();
    void toggledGlossyRadioBtn(bool checked);
    void toggledMatteRadioBtn(bool checked);
    void onloadSceneBtnClicked();
    void onclearSceneBtnClicked();
    void exitMenuTriggered();

private:
    // const char *getModelFilename(typeChess type_chess);
    void updateModelsTable();
    // void updateAllModelsComboBox(int index);
    void tableCellActivated(int row, int column);

    void rotateCamera(Axis axis, int sign);
    void moveCamera(int sign);
    void saveToFile();    

};




