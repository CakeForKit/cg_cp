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
                                std::make_shared<Material>( Intensity(0.0, 0.0, 0.0),    // ka
                                                            Intensity(0.5, 0.5, 0.5),       // kd
                                                            Intensity(0.5, 0.5, 0.5),       // ks
                                                            5)); 
    materialSolution.registrateMaterial(idMaterial::GLOSSY_BLACK, 
                                std::make_shared<Material>( Intensity(0, 0, 0),   // ka
                                                            Intensity(0, 0, 0),   // kd
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
                                                            // ( Intensity(0.07, 0.001, 0),   // ka
                                                            // Intensity(0.18, 0.003, 0),   // kd
                                                            // Intensity(0, 0, 0),   // ks
                                                            // 1)); 
    // materialSolution.registratePairMaterial(idPairMaterial::GLOSSY, idMaterial::GLOSSY_WHITE, idMaterial::GLOSSY_BLACK); 
    // materialSolution.registratePairMaterial(idPairMaterial::MATTE, idMaterial::MATTE_WHITE, idMaterial::MATTE_BLACK);  
    materialSolution.registratePairMaterial(idPairMaterial::BLUE_RED, idMaterial::BLUE, idMaterial::RED);                                              

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

