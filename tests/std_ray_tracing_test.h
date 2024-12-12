#pragma once

#include <gtest/gtest.h>
// #include <QGraphicsView>
// #include <QMainWindow>
// #include <QApplication>
#include "FacadeScene.h"
#include "QtDrawCommand.h"
#include "TrianglesModelLoadCommand.h"
#include "MoveModelCommand.h"
#include "RotateModelCommand.h"
#include "RotateCameraCommand.h"
#include "MaterialSolution.h"
#include "DrawTimeCommand.h"
#include "TrianglesChessboardLoadCommand.h"

struct raytracing_test_data_t {
    int xi;     // координата пикселя по x
    int yi;     // координата пикселя по y
    Intensity expIntens;    // ожидаемая интенсивность пикселя с координатами (xi, yi)
};


const raytracing_test_data_t raytracing_test_data[] = {
    { 261, 75, Intensity(0.3, 0.3, 0.3) },                       // нет пересечений луча
    { 231, 332, Intensity(0.734893, 0, 0) },    // луч пересекается с обьектом один раз
    { 219, 362, Intensity(0.341855, 0.0810562, 0.0810562) },       // луч пересекается с обьектом и отражается
    { 176, 324, Intensity(0.15, 0.15, 0.15) },       // луч пересекается с обьектом в тени др обьекта
};

// class Window : public QMainWindow
// {
//     Q_OBJECT
// public:
//     Window(QWidget *parent = 0);
//     ~Window() = default;

//     void closee();

//     QGraphicsScene* scene;
//     QGraphicsView* graphicsView;

//     void setImg(QImage &img);
// };