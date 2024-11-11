#include "intersection_type.h"


intersection_t& intersection_t::operator=(const intersection_t &v) noexcept {
    point = v.point;
    distance = v.distance;
    normal = v.normal;
    material = v.material;
    return *this;
}

intersection_t& intersection_t::operator=(intersection_t &&v) noexcept {
    point = v.point;
    distance = v.distance;
    normal = v.normal;
    material = v.material;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const intersection_t &interset) {
    os << "Intersection: Point" << interset.point << " dist= " << interset.distance << ", n= " << interset.normal << std::endl;
    return os;
}

