#include "Ray.h"

std::ostream& operator<<(std::ostream &os, const Ray &ray) {
    return os << "(orig=" << ray.getOrigin() << ", dir=" << ray.getDirection() << ")";
}

Ray::Ray(const Point3 &origin, const Vector3 &direction) noexcept 
: orig(origin), dir(direction) {}

Ray::Ray(const Ray &ray) noexcept
: orig(ray.getOrigin()), dir(ray.getDirection()) {}

Ray::Ray(Ray &&ray) noexcept
: orig(ray.getOrigin()), dir(ray.getDirection()) {}

Point3 Ray::getOrigin() const noexcept {
    return orig;
}

Vector3 Ray::getDirection() const noexcept {
    return dir;
}

Point3 Ray::operator()(float t) const noexcept {
    return orig + dir * t;
}

