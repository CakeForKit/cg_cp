#include "TrianglesModelBuilder.h"

TrianglesModelBuilder::TrianglesModelBuilder(std::shared_ptr<VolumeModelReader> reader)
: VolumeModelBuilder(reader) {
    model = std::make_shared<TrianglesModel>();
}