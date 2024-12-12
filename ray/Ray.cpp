#include "Ray.h"

std::ostream& operator<<(std::ostream &os, const Ray &ray) {
    return os << "(orig=" << ray.getOrigin() << ", dir=" << ray.getDirection() << ")";
}

Ray::Ray(const Point3 &origin, const Vector3 &direction) noexcept 
: orig(origin), dir(direction.normalized()) {}

Ray::Ray(const Point3 &&origin, const Vector3 &&direction) noexcept 
: orig(origin), dir(direction.normalized()) {}

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

Point3 Ray::operator()(double t) const noexcept {
    return orig + dir * t;
}

Ray& Ray::operator=(const Ray &r) noexcept {
    orig = r.getOrigin();
    dir = r.getDirection();
    return *this;
}

Ray& Ray::operator=(Ray &&r) noexcept {
    orig = r.getOrigin();
    dir = r.getDirection();
    return *this;
}

bool Ray::operator==(const Ray &r) const noexcept {
    return r.getDirection() == dir && r.getOrigin() == orig;
}

double Ray::dist2ToPoint(const Point3 &p) const noexcept {
    double tmin = -(dir.x() * (orig.x() - p.x()) + 
                    dir.y() * (orig.y() - p.y()) + 
                    dir.z() * (orig.z() - p.z())) / 
                    (dir.x() * dir.x() + 
                    dir.y() * dir.y() + 
                    dir.z() * dir.z());
    double xpart, ypart, zpart;
    xpart = (orig.x() + dir.x() * tmin - p.x());
    ypart = (orig.y() + dir.y() * tmin - p.y());
    zpart = (orig.z() + dir.z() * tmin - p.z());
    double dist2 = xpart * xpart + ypart * ypart + zpart * zpart;
    return dist2;
}