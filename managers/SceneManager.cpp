#include "SceneManager.h"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Scene> SceneManager::getScene() noexcept {
    return scene;
}

size_t SceneManager::getCountAllFaces() const noexcept {
    return scene->getCountAllFaces();
}

void SceneManager::addModel(std::shared_ptr<Model> model) noexcept {
    scene->addModel(model);
}

void SceneManager::removeModel(size_t ind) {
    scene->removeModel(ind);
}

std::shared_ptr<Model> SceneManager::getModel(size_t ind) {
    return scene->getModel(ind);
}

void SceneManager::addCamera() noexcept {
    scene->addCamera();
}

void SceneManager::removeCamera(size_t ind) {
    scene->removeCamera(ind);
}

std::shared_ptr<Camera> SceneManager::getActiveCamera() {
    return scene->getActiveCamera();
}

void SceneManager::setChessboard(std::shared_ptr<Chessboard> model) noexcept {
    scene->setChessboard(model);
}

Point3 SceneManager::changeModelPos(size_t idModel, size_t i, size_t j) {
    return scene->changeModelPos(idModel, i, j);
}

// Point3 SceneManager::getPosCell(size_t i, size_t j) const {
//     return scene->getPosCell(i, j);
// }

void SceneManager::writeDataToTable(QTableWidget *tab) const noexcept {
    QStringList header = {"id", "Фигура", "Цвет", "Позиция"};
    tab->setHorizontalHeaderLabels(header);

    tab->setRowCount(static_cast<int>(scene->countModels()));
    tab->setColumnCount(static_cast<int>(header.size()));

    char id[5], pos[3];
    int ii = 0;
    for (size_t i = 0; i < scene->countModels(); ++i, ++ii) {
        sprintf(id, "%ld", i + 1);
        PtrModel m = scene->getModel(i);
        tab->setItem(ii, 0, new QTableWidgetItem(id));
        tab->setItem(ii, 1, new QTableWidgetItem(mapNamesChess[m->getTypeChess()]));
        QPixmap myPixmap(10, 20);
        myPixmap.fill(m->getColor().getQColor());
        QIcon icon(myPixmap);
        tab->setItem(ii, 2, new QTableWidgetItem(icon, QString()));
        size_t pi, pj;
        assert(scene->getPosModel(i, pi, pj));
        pos[0] = static_cast<char>(96 + i);
        pos[1] = static_cast<char>(48 + i);
        pos[2] = 0;
        tab->setItem(ii, 3, new QTableWidgetItem(pos));
    }
}