#pragma once

#include "Material.h"

#include <map>
#include <memory>


enum class idMaterial {
    RED,
    BLUE,

    GLOSSY_WHITE,
    MATTE_WHITE,

    GLOSSY_BLACK,
    MATTE_BLACK,

    WOOD
};

enum class idPairMaterial {
    GLOSSY,
    MATTE,
    TMP
};

enum class indPair {
    WHITE,
    BLACK
};

class MaterialSolution
{
    using mapMaterial = std::map<idMaterial, std::shared_ptr<Material>>;
    using mapPairMaterial = std::map<idPairMaterial, std::pair<idMaterial, idMaterial>>;

private:
    mapMaterial map;
    mapPairMaterial pairMaterials;

public:
    bool registrateMaterial(idMaterial id, std::shared_ptr<Material> material);
    bool checkId(idMaterial id);

    std::shared_ptr<Material> getMaterial(idMaterial id);

    bool registratePairMaterial(idPairMaterial id, idMaterial m1, idMaterial m2);
    bool checkId(idPairMaterial id);
    std::shared_ptr<Material> getMaterial(idPairMaterial id, indPair ind);
};
