#pragma once

#include "Scene.h"

class SceneManager
{
protected:
    std::shared_ptr<Scene> scene;

public:
    SceneManager();

    std::shared_ptr<Scene> getScene() noexcept;
    size_t getCountAllFaces() const noexcept;
    size_t countModels() const noexcept;

    void addModel(std::shared_ptr<Model> model, size_t i, size_t j);
    void addModel(std::shared_ptr<Model> model);
    void removeModel(size_t ind);
    std::shared_ptr<Model> getModel(size_t ind);
    bool getPosModel(size_t idModel, size_t &i, size_t &j) const noexcept;

    void addCamera() noexcept;
    void removeCamera(size_t ind);
    std::shared_ptr<Camera> getActiveCamera();

    void setChessboard(std::shared_ptr<Chessboard> model) noexcept;
    Point3 changeModelPos(size_t idModel, size_t i, size_t j);
    // Point3 getPosCell(size_t i, size_t j) const;

};
