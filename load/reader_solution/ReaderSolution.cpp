#include "ReaderSolution.h"

bool ReaderSolution::registrate(idReaderCreator id, fCreateReaderCreator fcreate) {
    return map.insert(mapCreators::value_type(id, fcreate)).second;
}

bool ReaderSolution::checkId(idReaderCreator id) const noexcept {
    return map.find(id) != map.end();
}

std::shared_ptr<ReaderCreator> ReaderSolution::create(idReaderCreator id) {
    mapCreators::const_iterator it = map.find(id);

    if (it == map.end())
        return nullptr;
    else
        return std::shared_ptr<ReaderCreator>(it->second());
}

