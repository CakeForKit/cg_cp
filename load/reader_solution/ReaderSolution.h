#pragma once

#include "ReaderCreatorMaker.h"
#include <map>

enum class idReaderCreator {
    TRIANGLES
};

class ReaderSolution
{
    using fCreateReaderCreator = std::shared_ptr<ReaderCreator>(&)();
    using mapCreators = std::map<idReaderCreator, fCreateReaderCreator>;

private:
    mapCreators map;

public:
    ReaderSolution() = default;

    bool registrate(idReaderCreator id, fCreateReaderCreator fcreate);
    bool checkId(idReaderCreator id) const noexcept;

    std::shared_ptr<ReaderCreator> create(idReaderCreator id);
};
