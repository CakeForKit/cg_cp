#pragma once

#include "Scene.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QObject>

class SceneManager
{
protected:
    std::shared_ptr<Scene> scene;

public:
    SceneManager();

    std::shared_ptr<Scene> getScene() noexcept;
    size_t getCountAllFaces() const noexcept;

    void addModel(std::shared_ptr<Model> model) noexcept;
    void removeModel(size_t ind);
    std::shared_ptr<Model> getModel(size_t ind);

    void addCamera() noexcept;
    void removeCamera(size_t ind);
    std::shared_ptr<Camera> getActiveCamera();

    void setChessboard(std::shared_ptr<Chessboard> model) noexcept;
    Point3 changeModelPos(size_t idModel, size_t i, size_t j);
    // Point3 getPosCell(size_t i, size_t j) const;

    void writeDataToTable(QTableWidget *tab) const noexcept;
};
