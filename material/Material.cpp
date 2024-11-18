#include "Material.h"

std::ostream& Material::print(std::ostream &os) const noexcept {
    os << "Material:\n";
    os << "\tka = " << ka << "\n";
    os << "\tkd = " << kd << "\n";
    os << "\tks = " << ks << "\n";
    os << "\tn = " << n << "\n";
    return os;
}

std::ostream& operator<<(std::ostream &os, const Material &m) {
    return m.print(os);
}

Material::Material(Intensity &&_ka, Intensity &&_kd, Intensity &&_ks, double _n)
: ka(_ka), kd(_kd), ks(_ks), n(_n) {
    // double xsum, ysum, zsum;
    // xsum = ka.x() + kd.x() + 2 * ks.x();
    // ysum = ka.y() + kd.y() + 2 * ks.y();
    // zsum = ka.z() + kd.z() + 2 * ks.z();
    // assert(0 <= xsum && xsum <= 1.0 + EPS);
    // assert(0 <= ysum && ysum <= 1.0 + EPS);
    // assert(0 <= zsum && zsum <= 1.0 + EPS);
}

Material::Material(Material &m) {
    ka = m.getKa();
    kd = m.getKd();
    ks = m.getKs();
    n = m.getN();
}

const Intensity Material::getKa() const noexcept { return ka; }

const Intensity Material::getKd() const noexcept { return kd; }

const Intensity Material::getKs() const noexcept { return ks; }

double Material::getN() const noexcept { return n; }

Color Material::getColor() const noexcept {
    Intensity s = ka + kd + 2 * ks;
    return Color(s);
}

Material& Material::operator=(const Material &m) noexcept {
    ka = m.getKa();
    kd = m.getKd();
    ks = m.getKs();
    n = m.getN();
    return *this;
}