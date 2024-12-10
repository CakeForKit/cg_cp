#include "AllByOneSceneLoadCommand.h"


AllByOneSceneLoadCommand::AllByOneSceneLoadCommand(DataMaps &_fnMaps,
                                                size_t _stepOfRevolving) 
: BaseSceneLoadCommand(_fnMaps, _stepOfRevolving) {
    std::cout << "AllByOneSceneLoadCommand\n";
}
    
void AllByOneSceneLoadCommand::execute() {
    sceneManager->clearScene();
    {
        size_t i, j;
        indPair indPairMaterial = indPair::WHITE;
        std::shared_ptr<Material> material = materialManager->getActiveMaterial(indPairMaterial);
        i = 2;
        j = 0;
        loadModel(material, typeChess::PAWN, i++, j++);
        loadModel(material, typeChess::ROOK, i++, j++);
        loadModel(material, typeChess::KNIGHT, i++, j++);
        loadModel(material, typeChess::BISHOP, i++, j++);
        loadModel(material, typeChess::QUEEN, i++, j++);
        loadModel(material, typeChess::KING, i++, j++);
    }
    {
        size_t i, j;
        indPair indPairMaterial = indPair::BLACK;
        std::shared_ptr<Material> material = materialManager->getActiveMaterial(indPairMaterial);
        i = 0;
        j = 2;
        loadModel(material, typeChess::KING, i++, j++);
        loadModel(material, typeChess::QUEEN, i++, j++);
        loadModel(material, typeChess::BISHOP, i++, j++);
        loadModel(material, typeChess::KNIGHT, i++, j++);
        loadModel(material, typeChess::ROOK, i++, j++);
        loadModel(material, typeChess::PAWN, i++, j++);
    }
}