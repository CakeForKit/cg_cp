#include "Triangle.h"

std::ostream& operator<<(std::ostream &os, const Triangle &tr) {
    return os << "(" << *(tr[0]) << " - " << *(tr[1]) << " - " << *(tr[2]) << ")";
}

// Triangle::Triangle(Point3 &p1, Point3 &p2, Point3 &p3) {
//     if (p1 == p2 || p2 == p3 || p1 == p3) {
//         time_t curTime = time(NULL);
//         throw SamePointsTriangleException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
//     }
//     if (p3.isBelongsToLine(p1, p2)) {
//         time_t curTime = time(NULL);
//         throw DegenerateTriangleException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
//     }
//     points[0] = std::make_shared<Point3>(p1);
//     points[1] = std::make_shared<Point3>(p2);
//     points[2] = std::make_shared<Point3>(p3);
// }

Triangle::Triangle(psPoint3 &p1, psPoint3 &p2, psPoint3 &p3) {
    if (*p1 == *p2 || *p2 == *p3 || *p1 == *p3) {
        time_t curTime = time(NULL);
        throw SamePointsTriangleException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    if (p3->isBelongsToLine(*p1, *p2)) {
        time_t curTime = time(NULL);
        throw DegenerateTriangleException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
}

Triangle::Triangle(Triangle &&tr) noexcept {
    for (size_t i = 0; i < 3; ++i) {
        points[i] = tr[i];
    }
}

Triangle::Triangle(const Triangle &tr) {
    for (size_t i = 0; i < 3; ++i) {
        points[i] = tr[i];
    }
}

psPoint3 Triangle::operator[](size_t ind) const {
    if (ind >= 3) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return points[ind];
}

// Point3 &Triangle::operator[](size_t ind) {
//     if (ind >= 3) {
//         time_t curTime = time(NULL);
//         throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
//     }
//     return points[ind];
// }

Triangle& Triangle::operator=(const Triangle &tr) noexcept {
    for (size_t i = 0; i < 3; ++i)
        points[i] = tr[i];
    return *this;
}

Triangle& Triangle::operator=(Triangle &&tr) noexcept {
    for (size_t i = 0; i < 3; ++i)
        points[i] = tr[i];
    return *this;
}

bool Triangle::operator==(const Triangle &tr) const noexcept {
    bool point_same;
    for (size_t i = 0; i < 3; ++i) {
        point_same = false;
        for (size_t j = 0; !point_same && j < 3; ++j) {
            if (*(points[i]) == *(tr[j]))
                point_same = true;
        }
        if (!point_same)
            return false;
    }
    return true;
}

bool Triangle::operator!=(const Triangle &tr) const noexcept {
    return !(*this == tr);
}

void Triangle::print_debug_info() {
    std::cout << *this << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "use_count " << *points[i] << " = " << points[i].use_count() << std::endl;
    }
}
