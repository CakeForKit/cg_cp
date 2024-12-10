#pragma once

#include <iostream>
#include <QComboBox>

#include "MaterialSolution.h"
#include "Model.h"
#include "BaseLoadCommand.h"


class DataMaps 
{
private:
    std::map<typeChess, const char *> chessMap;
    std::map<idPairMaterial, const char *> pairMaterialsMap;
    std::map<indPair, const char *> pairColorsMap;
    std::map<typeScenes, const char *> sceneMap;

public:
    DataMaps();
    void fillModelsComboBox(QComboBox *cb);
    void fill_iPosComboBox(QComboBox *cb);
    void fill_jPosComboBox(QComboBox *cb);
    void fill_MaterialsComboBox(QComboBox *cb);
    void fill_ColorsComboBox(QComboBox *cb);
    void fill_ScenesComboBox(QComboBox *cb);

    const char *getFilename(typeChess index);

};
