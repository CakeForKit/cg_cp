#pragma once

#include "VolumeModelDirector.h"
#include "Chessboard.h"
#include "DataChessboardReader.h"


class ChessboardDirector : public Director
{
protected:
    std::shared_ptr<VolumeModelDirector> black_director;
    std::shared_ptr<VolumeModelDirector> white_director;
    std::shared_ptr<VolumeModelDirector> base_director;
    std::shared_ptr<DataChessboardReader> data_cells_reader;

    std::shared_ptr<Chessboard> chessboard;
    bool isBuilt = false;

public:
    ChessboardDirector(std::shared_ptr<VolumeModelDirector> _black_director,
                        std::shared_ptr<VolumeModelDirector> _white_director,
                        std::shared_ptr<VolumeModelDirector> _base_director, 
                        const char *fn_data_cells_reader);
    virtual ~ChessboardDirector() = default;

    virtual std::shared_ptr<Model> get();

protected:
    virtual void create();
};
