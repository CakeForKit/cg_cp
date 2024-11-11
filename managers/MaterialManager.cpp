#include "MaterialManager.h"

MaterialManager::MaterialManager() : materialSolution(MaterialSolution()) {

    materialSolution.registrate(idMaterial::RED, std::make_shared<Material>(Intensity(0.2, 0, 0),   // ka
                                                                            Intensity(0.6, 0, 0),   // kd
                                                                            Intensity(0.1, 0, 0),   // ks
                                                                            50));                   // n
    materialSolution.registrate(idMaterial::BLUE, std::make_shared<Material>(Intensity(0.157, 0.3, 0.34), 
                                                                            Intensity(0.213, 0.5, 0.56), 
                                                                            Intensity(0, 0, 0),
                                                                            5));
    materialSolution.registrate(idMaterial::GLOSSY_WHITE, 
                                std::make_shared<Material>( Intensity(0.15, 0.15, 0.15),    // ka
                                                            Intensity(0.6, 0.6, 0.6),       // kd
                                                            Intensity(0.2, 0.2, 0.2),       // ks
                                                            1)); 
    materialSolution.registrate(idMaterial::GLOSSY_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0, 0, 0),   // kd
                                                            Intensity(0.2, 0.2, 0.2),   // ks
                                                            5));    
    materialSolution.registrate(idMaterial::WOOD, 
                                std::make_shared<Material>( Intensity(0.066, 0.048, 0.034),   // ka
                                                            Intensity(0.66, 0.48, 0.34),   // (0.66, 0.48, 0.34) // kd
                                                            Intensity(0, 0, 0),   // ks
                                                            1));   
                                                            // ( Intensity(0.07, 0.001, 0),   // ka
                                                            // Intensity(0.18, 0.003, 0),   // kd
                                                            // Intensity(0, 0, 0),   // ks
                                                            // 1));   
                                                                                                                                                                
}

std::shared_ptr<Material> MaterialManager::getMaterial(idMaterial id) {
    return materialSolution.getMaterial(id);
}


