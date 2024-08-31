#include "VolumeModel.h"

std::ostream& VolumeModel::print(std::ostream &os) const noexcept {
    return impl->print(os);
}

VolumeModel::VolumeModel(std::shared_ptr<VolumeModelImpl> _impl) 
: impl(_impl) {}

// bool VolumeModel::addVertex(psPoint3 pv) {
//     return impl->addVertex(pv);
// }

// bool VolumeModel::addFace(std::initializer_list<psPoint3> &lst) {
//     return impl->addFace(lst);
// }

// bool VolumeModel::addFace(std::initializer_list<psPoint3> &&lst) {
//     return impl->addFace(lst);
// }

// void VolumeModel::setCenter(Point3 &c) {
//     impl->setCenter(c);
// }

container_vertices VolumeModel::getVertices() const noexcept {
    return impl->getVertices();
}

Point3 VolumeModel::getCenter() const noexcept {
    return impl->getCenter();
}

bool VolumeModel::intersection(const Ray &ray, intersection_t &intersect) const {
    return impl->intersection(ray, intersect);
}