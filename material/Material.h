#pragma once

#include "Vector3.h"
#include "assert.h"
#include "Color.h"

class Material
{
protected:
    // Intensity objIntensity;
    Intensity ka;   // коэф дифузного отражения рассеянного света
    Intensity kd;   // коэф дифузного отражения
    Intensity ks;   // коэф зеркального отражения
    double n;       // степень, аппроксимирующая пространственное распределение зеркально отражённого света

public:
    Material(Intensity &&_ka, Intensity &&_kd, Intensity &&_ks, double _n);
    Material(Material &m);

    const Intensity getKa() const noexcept;
    const Intensity getKd() const noexcept;
    const Intensity getKs() const noexcept;
    double getN() const noexcept;
    Color getColor() const noexcept;

    Material& operator=(const Material &m) noexcept;

    std::ostream& print(std::ostream &os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Material &m);
