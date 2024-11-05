#include "LoadManager.h"


LoadManager::LoadManager() {
    bool rv;
    rv = readerSolution.registrate(idReaderCreator::TRIANGLES, std::make_shared<TrianglesModelReaderCreator_t>());
    assert(rv);
    rv = directorSolution.registrate(idDirectorCreator::TRIANGLES, std::make_shared<TrianglesModelDirectorCreator_t>());
    assert(rv);
    rv = directorSolution.registrate(idDirectorCreator::CHESSBOARD, std::make_shared<ChessboardDirectorCreator_t>());
    assert(rv);
}

std::shared_ptr<Model> LoadManager::loadModelFromFile(idReaderCreator id_reader, 
                                                            idDirectorCreator id_director, 
                                                            const char *filename, 
                                                            size_t stepOfRevolving,
                                                            std::shared_ptr<Material> material) {

    std::shared_ptr<BaseReaderCreator> readerCreator(readerSolution.create(id_reader));
    std::shared_ptr<TrianglesModelReaderCreator_t> trinaglesModelReaderCreator  = std::dynamic_pointer_cast<TrianglesModelReaderCreator_t>(readerCreator);
    assert(trinaglesModelReaderCreator != nullptr);

    std::shared_ptr<VolumeModelReader> reader = trinaglesModelReaderCreator->createReader(filename, stepOfRevolving); 
    

    std::shared_ptr<BaseDirectorCreator> directorCreator(directorSolution.create(id_director));
    std::shared_ptr<TrianglesModelDirectorCreator_t> trianglesModelDirectorCreator = std::dynamic_pointer_cast<TrianglesModelDirectorCreator_t>(directorCreator);
    assert(trianglesModelDirectorCreator != nullptr);
    
    std::shared_ptr<VolumeModelDirector> director = trianglesModelDirectorCreator->createDirector(reader, material);
    return director->get();
}

std::shared_ptr<Model> LoadManager::loadChessboardFromFile(idReaderCreator id_reader, 
                                                    idDirectorCreator id_director, 
                                                    const char *fnBlackCells,
                                                    std::shared_ptr<Material> matBlackCells, 
                                                    const char *fnWhiteCells,
                                                    std::shared_ptr<Material> matWhiteCells, 
                                                    const char *fnBase,
                                                    std::shared_ptr<Material> matBase) {
    std::shared_ptr<BaseReaderCreator> readerCreator(readerSolution.create(id_reader));
    std::shared_ptr<TrianglesModelReaderCreator_t> trinaglesModelReaderCreator  = std::dynamic_pointer_cast<TrianglesModelReaderCreator_t>(readerCreator);
    assert(trinaglesModelReaderCreator != nullptr);

    std::shared_ptr<BaseDirectorCreator> directorCreator(directorSolution.create(id_director));
    std::shared_ptr<TrianglesModelDirectorCreator_t> trianglesModelDirectorCreator = std::dynamic_pointer_cast<TrianglesModelDirectorCreator_t>(directorCreator);
    assert(trianglesModelDirectorCreator != nullptr);

    size_t tmp = 3;
    std::shared_ptr<VolumeModelReader> bc_reader = trinaglesModelReaderCreator->createReader(fnBlackCells, tmp); 
    std::shared_ptr<VolumeModelDirector> bc_director = trianglesModelDirectorCreator->createDirector(bc_reader, matBlackCells);
    std::shared_ptr<VolumeModelReader> wc_reader = trinaglesModelReaderCreator->createReader(fnWhiteCells, tmp); 
    std::shared_ptr<VolumeModelDirector> wc_director = trianglesModelDirectorCreator->createDirector(wc_reader, matWhiteCells);
    std::shared_ptr<VolumeModelReader> b_reader = trinaglesModelReaderCreator->createReader(fnBase, tmp); 
    std::shared_ptr<VolumeModelDirector> b_director = trianglesModelDirectorCreator->createDirector(b_reader, matBase);

    std::shared_ptr<BaseDirectorCreator> cbDirectorCreator(directorSolution.create(idDirectorCreator::CHESSBOARD));
    std::shared_ptr<ChessboardDirectorCreator_t> chessboardDirectorCreator = std::dynamic_pointer_cast<ChessboardDirectorCreator_t>(cbDirectorCreator);
    assert(chessboardDirectorCreator != nullptr);

    std::shared_ptr<ChessboardDirector> chessboard_director = chessboardDirectorCreator->createDirector(bc_director, wc_director, b_director);
    return chessboard_director->get();
}
