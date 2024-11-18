#include "MaterialManager.h"

MaterialManager::MaterialManager() : materialSolution(MaterialSolution()) {

    materialSolution.registrateMaterial(idMaterial::RED, std::make_shared<Material>(Intensity(0.2, 0, 0),   // ka
                                                                            Intensity(0.6, 0, 0),   // kd
                                                                            Intensity(0.1, 0, 0),   // ks
                                                                            50));                   // n
    materialSolution.registrateMaterial(idMaterial::BLUE, std::make_shared<Material>(Intensity(0.157, 0.3, 0.34), 
                                                                            Intensity(0.213, 0.5, 0.56), 
                                                                            Intensity(0, 0, 0),
                                                                            5));
    materialSolution.registrateMaterial(idMaterial::GLOSSY_WHITE, 
                                std::make_shared<Material>( Intensity(0.05, 0.05, 0.05),    // ka
                                                            Intensity(0.85, 0.85, 0.85),       // kd
                                                            Intensity(0.15, 0.15, 0.15),       // ks
                                                            5)); 
    materialSolution.registrateMaterial(idMaterial::MATTE_WHITE, 
                                std::make_shared<Material>( Intensity(0.15, 0.15, 0.15),    // ka
                                                            Intensity(0.75, 0.75, 0.75),       // kd
                                                            Intensity(0, 0, 0),       // ks
                                                            1));                                                             
    materialSolution.registrateMaterial(idMaterial::GLOSSY_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0.25, 0.25, 0.25),   // kd
                                                            Intensity(0.1, 0.1, 0.1),   // ks
                                                            5));    
    materialSolution.registrateMaterial(idMaterial::MATTE_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0.3, 0.3, 0.3),   // kd
                                                            Intensity(0, 0, 0),   // ks
                                                            1));                                   
    materialSolution.registrateMaterial(idMaterial::WOOD, 
                                std::make_shared<Material>( Intensity(0.066, 0.048, 0.034),   // ka
                                                            Intensity(0.66, 0.48, 0.34),   // (0.66, 0.48, 0.34) // kd
                                                            Intensity(0, 0, 0),   // ks
                                                            1));   
                                                            // ( Intensity(0.07, 0.001, 0),   // ka
                                                            // Intensity(0.18, 0.003, 0),   // kd
                                                            // Intensity(0, 0, 0),   // ks
                                                            // 1)); 
    materialSolution.registratePairMaterial(idPairMaterial::GLOSSY, idMaterial::GLOSSY_WHITE, idMaterial::GLOSSY_BLACK); 
    materialSolution.registratePairMaterial(idPairMaterial::MATTE, idMaterial::MATTE_WHITE, idMaterial::MATTE_BLACK);  
    materialSolution.registratePairMaterial(idPairMaterial::TMP, idMaterial::BLUE, idMaterial::RED);                                              

    activeMaterial_0 = std::make_shared<Material>(*getMaterial(idPairMaterial::GLOSSY, indPair::WHITE));            
    activeMaterial_1 = std::make_shared<Material>(*getMaterial(idPairMaterial::GLOSSY, indPair::BLACK));                                                                                                                                                                
}

std::shared_ptr<Material> MaterialManager::getMaterial(idMaterial id) {
    return materialSolution.getMaterial(id);
}

std::shared_ptr<Material> MaterialManager::getMaterial(idPairMaterial id, indPair ind) {
    return materialSolution.getMaterial(id, ind);
}

bool MaterialManager::changeActiveMaterial(idPairMaterial idPair) {
    if (!materialSolution.checkId(idPair))
        return false;

    *activeMaterial_0 = *getMaterial(idPair, indPair::WHITE);
    *activeMaterial_1 = *getMaterial(idPair, indPair::BLACK);
    std::cout << "MaterialManager: " << *activeMaterial_0 << "\n\n";
    return true;
}

std::shared_ptr<Material> MaterialManager::getActiveMaterial(indPair ind) {
    if (ind == indPair::WHITE)
        return activeMaterial_0;
    else
        return activeMaterial_1;
}


