#include "MaterialManager.h"

MaterialManager::MaterialManager() : materialSolution(MaterialSolution()) {

    materialSolution.registrateMaterial(idMaterial::RED, 
                                    std::make_shared<Material>( Intensity(0.10, 0.00, 0.00),    // ka
                                                                Intensity(0.79, 0.00, 0.00),       // kd
                                                                Intensity(0.05, 0.00, 0.00),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::BLUE, 
                                    std::make_shared<Material>( Intensity(0.04, 0.08, 0.09),    // ka
                                                                Intensity(0.29, 0.63, 0.71),       // kd
                                                                Intensity(0.02, 0.04, 0.05),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::CLASSIC_WHITE, 
                                    std::make_shared<Material>( Intensity(0.10, 0.09, 0.07),    // ka
                                                                Intensity(0.79, 0.71, 0.57),       // kd
                                                                Intensity(0.05, 0.05, 0.04),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::CLASSIC_BLACK, 
                                    std::make_shared<Material>( Intensity(0.06, 0.03, 0.00),    // ka
                                                                Intensity(0.45, 0.24, 0.04),       // kd
                                                                Intensity(0.03, 0.02, 0.00),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::ORANGE, 
                                    std::make_shared<Material>( Intensity(0.10, 0.06, 0.00),    // ka
                                                                Intensity(0.79, 0.47, 0.00),       // kd
                                                                Intensity(0.05, 0.03, 0.00),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::PURPLE, 
                                    std::make_shared<Material>( Intensity(0.06, 0.00, 0.10),    // ka
                                                                Intensity(0.49, 0.00, 0.79),       // kd
                                                                Intensity(0.03, 0.00, 0.05),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::PINK, 
                                    std::make_shared<Material>( Intensity(0.10, 0.00, 0.08),    // ka
                                                                Intensity(0.79, 0.00, 0.62),       // kd
                                                                Intensity(0.05, 0.00, 0.04),       // ks
                                                                5)); 
    materialSolution.registrateMaterial(idMaterial::GREEN, 
                                    std::make_shared<Material>( Intensity(0.00, 0.06, 0.00),    // ka
                                                                Intensity(0.00, 0.46, 0.00),       // kd
                                                                Intensity(0.00, 0.03, 0.00),       // ks
                                                                5)); 

    materialSolution.registrateMaterial(idMaterial::GLOSSY_WHITE, 
                                std::make_shared<Material>( Intensity(0.0, 0.0, 0.0),    // ka
                                                            Intensity(0.5, 0.5, 0.5),       // kd
                                                            Intensity(0.5, 0.5, 0.5),       // ks
                                                            5)); 
    materialSolution.registrateMaterial(idMaterial::GLOSSY_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0.1, 0.1, 0.1),   // kd
                                                            Intensity(0.5, 0.5, 0.5),   // ks
                                                            5));                                                               
    materialSolution.registrateMaterial(idMaterial::MATTE_WHITE, 
                                std::make_shared<Material>( Intensity(0.1, 0.1, 0.1),    // ka
                                                            Intensity(0.7, 0.7, 0.7),       // kd
                                                            Intensity(0, 0, 0),       // ks
                                                            5));                                                              
    materialSolution.registrateMaterial(idMaterial::MATTE_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0.2, 0.2, 0.2),   // kd
                                                            Intensity(0, 0, 0),   // ks
                                                            5));                                     
    materialSolution.registrateMaterial(idMaterial::WOOD, 
                                std::make_shared<Material>( Intensity(0.066, 0.048, 0.034),   // ka
                                                            Intensity(0.66, 0.48, 0.34),   // (0.66, 0.48, 0.34) // kd
                                                            Intensity(0, 0, 0),   // ks
                                                            1));     
    materialSolution.registratePairMaterial(idPairMaterial::BLUE_RED, idMaterial::BLUE, idMaterial::RED);                                              
    materialSolution.registratePairMaterial(idPairMaterial::CLASSIC, idMaterial::CLASSIC_WHITE, idMaterial::CLASSIC_BLACK);      
    materialSolution.registratePairMaterial(idPairMaterial::ORANGE_PURPLE, idMaterial::ORANGE, idMaterial::PURPLE);      
    materialSolution.registratePairMaterial(idPairMaterial::PINK_GREEN, idMaterial::PINK, idMaterial::GREEN);      

    activeMaterial_0 = std::make_shared<Material>(*getMaterial(idPairMaterial::BLUE_RED, indPair::WHITE));            
    activeMaterial_1 = std::make_shared<Material>(*getMaterial(idPairMaterial::BLUE_RED, indPair::BLACK));         

    chessboardWhite = std::make_shared<Material>(*getMaterial(idMaterial::GLOSSY_WHITE));            
    chessboardBlack = std::make_shared<Material>(*getMaterial(idMaterial::GLOSSY_BLACK));                                                                                                                                                          
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

void MaterialManager::setChessboardMaterial(idChessboardMaterial id) {
    if (id == idChessboardMaterial::GLOSSY) {
        *chessboardWhite = *getMaterial(idMaterial::GLOSSY_WHITE);
        *chessboardBlack = *getMaterial(idMaterial::GLOSSY_BLACK);
    } else {
        *chessboardWhite = *getMaterial(idMaterial::MATTE_WHITE);
        *chessboardBlack = *getMaterial(idMaterial::MATTE_BLACK);
    }
}

std::shared_ptr<Material>  MaterialManager::getChessboardWhite() {
    return chessboardWhite;
}

std::shared_ptr<Material>  MaterialManager::getChessboardBlack() {
    return chessboardBlack;
}

