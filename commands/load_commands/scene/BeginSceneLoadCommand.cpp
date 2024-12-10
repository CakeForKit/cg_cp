#include "BeginSceneLoadCommand.h"


BeginSceneLoadCommand::BeginSceneLoadCommand(DataMaps &_fnMaps,
                                                size_t _stepOfRevolving) 
: BaseSceneLoadCommand(_fnMaps, _stepOfRevolving) {
    std::cout << "BeginSceneLoadCommand\n";
}
    
void BeginSceneLoadCommand::execute() {
    sceneManager->clearScene();
    indPair indPairMaterial;
    
    indPairMaterial = indPair::WHITE;
    loadPlayerModels(indPairMaterial);
    
    indPairMaterial = indPair::BLACK;
    loadPlayerModels(indPairMaterial);
}

void BeginSceneLoadCommand::loadPlayerModels(indPair indPairMaterial) {
    std::shared_ptr<Material> material = materialManager->getActiveMaterial(indPairMaterial);
    size_t j, pj;
    if (indPairMaterial == indPair::WHITE) {
        j = 0;
        pj = 1;
    } else {
        j = 7;
        pj = 6;
    }
    typeChess tChess;  

    tChess = typeChess::PAWN;
    for (size_t pi = 0; pi < 8; ++pi) {
        loadModel(material, tChess, pi, pj);
    }
    tChess = typeChess::ROOK;
    loadModel(material, tChess, 0, j);
    loadModel(material, tChess, 7, j);

    tChess = typeChess::KNIGHT;
    loadModel(material, tChess, 1, j);
    loadModel(material, tChess, 6, j);

    tChess = typeChess::BISHOP;
    loadModel(material, tChess, 2, j);
    loadModel(material, tChess, 5, j);

    tChess = typeChess::QUEEN;
    loadModel(material, tChess, 3, j);

    tChess = typeChess::KING;
    loadModel(material, tChess, 4, j);
}