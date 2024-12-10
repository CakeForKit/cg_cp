#include "TestSceneLoadCommand.h"


TestSceneLoadCommand::TestSceneLoadCommand(size_t _stepOfRevolving) 
: stepOfRevolving(_stepOfRevolving) { 
    id_director = idDirectorCreator::TRIANGLES; 
    id_reader = idReaderCreator::TRIANGLES;
    std::cout << "TestSceneLoadCommand\n";
}
    
void TestSceneLoadCommand::execute() {
    sceneManager->clearScene();
    {
        const char *filename = "/home/kathrine/cg_cp/tests/data_for_tests/test_model_4.txt";
        std::shared_ptr<Material> material = materialManager->getMaterial(idMaterial::GLOSSY_WHITE);
        PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
        sceneManager->addModel(model, 3, 4);
    }
    {
        const char *filename = "/home/kathrine/cg_cp/tests/data_for_tests/pawn.txt";
        std::shared_ptr<Material> material = materialManager->getMaterial(idMaterial::RED);
        PtrModel model = loadManager->loadModelFromFile(id_reader, id_director, filename, stepOfRevolving, material);
        sceneManager->addModel(model, 4, 4);
    }
}