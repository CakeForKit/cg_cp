#include "dataMaps.h"

DataMaps::DataMaps() {
    chessMap = {
        {typeChess::PAWN, "/home/kathrine/cg_cp/data/pawn.txt"},
        {typeChess::ROOK, "/home/kathrine/cg_cp/data/rook.txt"},
        {typeChess::KNIGHT, "/home/kathrine/cg_cp/data/knight.txt"},
        {typeChess::BISHOP, "/home/kathrine/cg_cp/data/bishop.txt"},
        {typeChess::QUEEN, "/home/kathrine/cg_cp/data/queen.txt"},
        {typeChess::KING, "/home/kathrine/cg_cp/data/king.txt"},
    };
    pairMaterialsMap = {
        {idPairMaterial::BLUE_RED, "Голубой-красный"},
        {idPairMaterial::CLASSIC, "Классический"},
        {idPairMaterial::ORANGE_PURPLE, "Оранжевый-фиолетовый"},
        {idPairMaterial::PINK_GREEN, "Розовый-зеленый"},
    };
    pairColorsMap = {
        {indPair::WHITE, "Игрок 1"},
        {indPair::BLACK, "Игрок 2"}
    };
    sceneMap = {
        {typeScenes::BEGIN, "Начальная расстановка"},
        {typeScenes::ALLBYONE, "Все фигуры"}
        // , {typeScenes::TEST, "Тест"}
    };
}


void DataMaps::fillModelsComboBox(QComboBox *cb) {
    for (std::map<typeChess, const char *>::iterator it = chessMap.begin(); it != chessMap.end(); ++it) {
        typeChess elem = it->first;
        cb->insertItem(static_cast<int>(elem), QString(mapNamesChess[elem]));
    }
}

void DataMaps::fill_iPosComboBox(QComboBox *cb) {
    for (int i = 1; i <= 8; ++i) {
        char c[2];
        c[0] = static_cast<char>(96 + i);
        c[1] = 0;
        cb->insertItem(i, &(c[0]));
    }
}

void DataMaps::fill_jPosComboBox(QComboBox *cb) {
    for (int i = 1; i <= 8; ++i) {
        char c[2];
        c[0] = static_cast<char>(48 + i);
        c[1] = 0;
        cb->insertItem(i, &(c[0]));
    }
}

void DataMaps::fill_MaterialsComboBox(QComboBox *cb) {
    for (std::map<idPairMaterial, const char *>::iterator it = pairMaterialsMap.begin(); 
    it != pairMaterialsMap.end(); ++it) {
        idPairMaterial elem = it->first;
        cb->insertItem(static_cast<int>(elem), QString(pairMaterialsMap[elem]));
    }
}

void DataMaps::fill_ColorsComboBox(QComboBox *cb) {
    for (indPair elem : {indPair::WHITE, indPair::BLACK})
        cb->insertItem(static_cast<int>(elem), QString(pairColorsMap[elem]));
}

void DataMaps::fill_ScenesComboBox(QComboBox *cb) {
    for (std::map<typeScenes, const char *>::iterator it = sceneMap.begin(); it != sceneMap.end(); ++it) {
        typeScenes elem = it->first;
        cb->insertItem(static_cast<int>(elem), QString(sceneMap[elem]));
    }
}

const char *DataMaps::getFilename(typeChess index) {
    return chessMap[index];
}
