#pragma once

#include <memory>
#include "Vector3.h"
#include "Exceptions.h"

class Triangle
{
protected:
    // не повторяются, не вырождаются в линию или точку
    psPoint3 points[3]; 
    // Vector3 normal; // внутренняя нормаль

public:
    // Triangle(Point3 &p1, Point3 &p2, Point3 &p3);
    Triangle(psPoint3 &p1, psPoint3 &p2, psPoint3 &p3);
    Triangle(Triangle &&tr) noexcept;
    explicit Triangle(const Triangle &tr);

    psPoint3 operator[](size_t ind) const;
    // Point3 &operator[](size_t ind);

    Triangle& operator=(const Triangle &tr) noexcept;
    Triangle& operator=(Triangle &&tr) noexcept;

    // сравнивает не указатели на точки а сами сочки, их координаты
    bool operator==(const Triangle &tr) const noexcept;
    bool operator!=(const Triangle &tr) const noexcept;


    void print_debug_info();

};

std::ostream& operator<<(std::ostream &os, const Triangle &tr);

using psTriangle = std::shared_ptr<Triangle>;