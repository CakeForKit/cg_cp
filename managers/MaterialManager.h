#pragma once

#include "MaterialSolution.h"


class MaterialManager
{
protected:
    MaterialSolution materialSolution;
    std::shared_ptr<Material> activeMaterial_0, activeMaterial_1;

public:
    MaterialManager();

    std::shared_ptr<Material> getMaterial(idMaterial id);
    std::shared_ptr<Material> getMaterial(idPairMaterial id, indPair ind);

    bool changeActiveMaterial(idPairMaterial idPair);
    std::shared_ptr<Material> getActiveMaterial(indPair ind);
};
