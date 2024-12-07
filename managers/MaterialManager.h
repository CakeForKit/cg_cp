#pragma once

#include "MaterialSolution.h"


class MaterialManager
{
protected:
    MaterialSolution materialSolution;
    std::shared_ptr<Material> activeMaterial_0, activeMaterial_1;
    std::shared_ptr<Material> chessboardWhite, chessboardBlack;

public:
    MaterialManager();

    std::shared_ptr<Material> getMaterial(idMaterial id);
    std::shared_ptr<Material> getMaterial(idPairMaterial id, indPair ind);

    bool changeActiveMaterial(idPairMaterial idPair);
    std::shared_ptr<Material> getActiveMaterial(indPair ind);

    void setChessboardMaterial(idChessboardMaterial id);
    std::shared_ptr<Material>  getChessboardWhite();
    std::shared_ptr<Material>  getChessboardBlack();
};
