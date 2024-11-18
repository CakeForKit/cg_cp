#pragma once

#include <iostream>
#include <QComboBox>

#include "MaterialSolution.h"
#include "Model.h"


class DataMaps 
{
private:
    // struct chess_t {
    //     const char *text;
    //     const char *filename;
    // };
    std::map<typeChess, const char *> chessMap;

    std::map<idPairMaterial, const char *> pairMaterialsMap;
    std::map<indPair, const char *> pairColorsMap;

public:
    DataMaps();
    void fillModelsComboBox(QComboBox *cb);
    void fill_iPosComboBox(QComboBox *cb);
    void fill_jPosComboBox(QComboBox *cb);
    void fill_MaterialsComboBox(QComboBox *cb);
    void fill_ColorsComboBox(QComboBox *cb);

    const char *getFilename(typeChess index);

};
