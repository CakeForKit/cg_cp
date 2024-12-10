#pragma once

#include "Material.h"

#include <map>
#include <memory>


enum class idMaterial {
    RED,
    BLUE,

    CLASSIC_WHITE,
    CLASSIC_BLACK,

    ORANGE,
    PURPLE,

    PINK,
    GREEN,

    GLOSSY_WHITE,
    MATTE_WHITE,

    GLOSSY_BLACK,
    MATTE_BLACK,

    WOOD
};

enum class idPairMaterial {
    BLUE_RED,
    CLASSIC,
    ORANGE_PURPLE,
    PINK_GREEN
};

enum class indPair {
    WHITE,
    BLACK
};

enum class idChessboardMaterial {
    GLOSSY,
    MATTE
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
