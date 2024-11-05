#include "ChessboardDirector.h"

ChessboardDirector::ChessboardDirector(
    std::shared_ptr<VolumeModelDirector> _black_director,
    std::shared_ptr<VolumeModelDirector> _white_director,
    std::shared_ptr<VolumeModelDirector> _base_director) {
        black_director = _black_director;
        white_director = _white_director;
        base_director = _base_director;
        isBuilt = false;
    }
    

std::shared_ptr<Model> ChessboardDirector::get() {
    if (!isBuilt) {
        create();
    }
    return chessboard;
}


void ChessboardDirector::create() {
    std::shared_ptr<Model> black_cells = black_director->get();
    std::shared_ptr<Model> white_cells = white_director->get();
    std::shared_ptr<Model> base = base_director->get();

    chessboard = std::make_shared<Chessboard>(black_cells, white_cells, base);
    isBuilt = true;
}