#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "ui_mainWindow.h"
#include "FacadeScene.h"
#include "QtDrawCommand.h"
#include "TrianglesModelLoadCommand.h"
#include "MaterialSolution.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parant = nullptr);

private:
    Ui::MainWindow ui;
    FacadeScene facade;
    MaterialSolution materialSolution;

private slots:
    void onPushButtonClicked();

};
