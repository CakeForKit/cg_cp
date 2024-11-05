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

class MaterialSolution
{
    using mapMaterial = std::map<idMaterial, std::shared_ptr<Material>>;

private:
    mapMaterial map;

public:
    bool registrate(idMaterial id, std::shared_ptr<Material> material);
    bool checkId(idMaterial id);

    std::shared_ptr<Material> getMaterial(idMaterial id);
};
