#include "VolumeModelBuilder.h"

VolumeModelBuilder::~VolumeModelBuilder() = default;

VolumeModelBuilder::VolumeModelBuilder(std::shared_ptr<VolumeModelReader> _reader, std::shared_ptr<Material> _material)
: reader(_reader), material(_material) {}

void VolumeModelBuilder::readData() {
    if (part != 0)
        return;

    reader->open();
    reader->readData();
    reader->close();

    ++part;
}

void VolumeModelBuilder::buildFaces() {
    if (!(part == 1 || part == 2 || part == 3))
        return;

    std::vector<std::vector<psPoint3>> faces = reader->getFaces();
    if (faces.size() == 0) {
        time_t curTime = time(NULL);
        throw NoFacesBuilderException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);

    }

    for (std::vector<psPoint3> elem : faces) {
        model->addFace(elem);       
    }
    ++part;
}

void VolumeModelBuilder::buildCenter() {
    if (!(part == 1 || part == 2 || part == 3))
        return;
        
    model->setCenter(reader->getCenter());

    ++part;
}

void VolumeModelBuilder::buildSphere() {
    if (!(part == 1 || part == 2 || part == 3))
        return;

    model->setSphereRad(reader->getSphereRad());
    model->setY0(reader->getY0());

    ++part;
}

bool VolumeModelBuilder::isBuilt() const noexcept {
    return part == 4;
}

std::shared_ptr<Model> VolumeModelBuilder::getModel() {
    return std::make_shared<VolumeModel>(model, material);
}