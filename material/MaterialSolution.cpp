#include "MaterialSolution.h"

bool MaterialSolution::registrateMaterial(idMaterial id, std::shared_ptr<Material> material) {
    return map.insert(mapMaterial::value_type(id, material)).second;
}

bool MaterialSolution::checkId(idMaterial id) {
    return map.find(id) != map.end();
}

std::shared_ptr<Material> MaterialSolution::getMaterial(idMaterial id) {
    mapMaterial::const_iterator it = map.find(id);

    if (it == map.end())
        return nullptr;
    else {
        mapMaterial::value_type elem = *it;
        return std::shared_ptr<Material>(elem.second);
    }
}

bool MaterialSolution::registratePairMaterial(idPairMaterial id, idMaterial m1, idMaterial m2) {
    return pairMaterials.insert(mapPairMaterial::value_type(id, {m1, m2})).second;
}

bool MaterialSolution::checkId(idPairMaterial id) {
    return pairMaterials.find(id) != pairMaterials.end();
}

std::shared_ptr<Material> MaterialSolution::getMaterial(idPairMaterial id, indPair ind) {
    mapPairMaterial::const_iterator it = pairMaterials.find(id);

    if (it == pairMaterials.end())
        return nullptr;
    else {
        mapPairMaterial::value_type elem = *it;
        std::pair<idMaterial, idMaterial> p = elem.second;
        if (ind == indPair::WHITE)
            return getMaterial(p.first);
        else
            return getMaterial(p.second);
    }
}