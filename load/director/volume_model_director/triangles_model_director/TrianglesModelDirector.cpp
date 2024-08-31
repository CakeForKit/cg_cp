#include "TrianglesModelDirector.h"

TrianglesModelDirector::TrianglesModelDirector(std::shared_ptr<VolumeModelReader> reader)
: VolumeModelDirector(reader) {
    builder = std::make_shared<TrianglesModelBuilder>(reader);
}
