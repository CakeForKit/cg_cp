#include "VolumeModel.h"

std::ostream& VolumeModel::print(std::ostream &os) const noexcept {
    impl->print(os);
    os << *material << std::endl;
    return os;
}

VolumeModel::VolumeModel(std::shared_ptr<VolumeModelImpl> _impl, std::shared_ptr<Material> _material) 
: impl(_impl), material(_material) {}

bool VolumeModel::isComposite() const { return false; }

container_vertices VolumeModel::getVertices() const noexcept {
    return impl->getVertices();
}

bool VolumeModel::intersection(const Ray &ray, intersection_t &intersect) const {
    intersect.material = material;
    return impl->intersection(ray, intersect);
}

void VolumeModel::transform(const std::shared_ptr<TransformAction> action) {
    impl->transform(action);
}

Point3 VolumeModel::getCenter() noexcept {
    return impl->getCenter();
}

Color VolumeModel::getColor() const {
    return material->getColor();
}

void VolumeModel::setMaterial(std::shared_ptr<Material> _material) noexcept {
    material = _material;
}

std::shared_ptr<Material> VolumeModel::getMaterial() const noexcept {
    return material;
}

size_t VolumeModel::getCountFaces() const noexcept {
    return impl->getCountFaces();
}