#include "TrianglesModel.h"

std::ostream& TrianglesModel::print(std::ostream &os) const noexcept {
    os << "TrianglesModel: \n\tVertices: [ ";
    for (psPoint3 v: vertices) {
        os << *v << " ";
    }
    os << "]\n\tTriangles: [ ";
    for (psTriangle tr : triangles) {
        os << *tr << " ";
    }
    os << "]\n\tCenter: " << center << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream &os, const TrianglesModel &model) {
    return model.print(os);
}

TrianglesModel::TrianglesModel() 
: vertices(std::unordered_set<psPoint3>()), triangles(std::unordered_set<psTriangle>()), center(Point3()) {}

bool TrianglesModel::addVertex(psPoint3 pv) noexcept {
    std::pair<std::unordered_set<psPoint3>::iterator, bool> rv = vertices.insert(pv);
    return rv.second;
}

bool TrianglesModel::addFace(std::initializer_list<psPoint3> &lst) {
    if (lst.size() != 3) {
        time_t curTime = time(NULL);
        throw SizeFaceTrianglesModelException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    psPoint3 points[3];
    size_t i = 0;
    for (psPoint3 elem : lst) {
        points[i] = elem;
        ++i;
    }

    psTriangle tr = std::make_shared<Triangle>(points[0], points[1], points[2]);
    std::pair<std::unordered_set<psTriangle>::iterator, bool> rv = triangles.insert(tr);
    return rv.second;
}

bool TrianglesModel::addFace(std::initializer_list<psPoint3> &&lst) {
    std::initializer_list<psPoint3> _lst(lst);
    return this->addFace(_lst);
}

// bool TrianglesModel::addTriangle(psTriangle ptr) noexcept {
//     std::pair<std::unordered_set<psTriangle>::iterator, bool> rv = triangles.insert(ptr);
//     return rv.second;
// }

void TrianglesModel::setCenter(Point3 &c) noexcept {
    center = c;
}

void TrianglesModel::setCenter(Point3 &&c) noexcept {
    center = c;
}

std::unordered_set<psPoint3> TrianglesModel::getVertices() const noexcept {
    return vertices;
}

std::unordered_set<psTriangle> TrianglesModel::getTriangles() const noexcept {
    return triangles;
}

Point3 TrianglesModel::getCenter() const noexcept {
    return center;
}

bool TrianglesModel::intersection(const Ray &ray, intersection_t &intersect) const {
    double t_value, min_t_value = std::numeric_limits<double>::max();
    psTriangle trIntersect;

    for (psTriangle tr : triangles) {
        if (tr->intersection(ray, t_value) && t_value < min_t_value) {
            min_t_value = t_value;
            trIntersect = tr;
        }
    }
    if (fabs(std::numeric_limits<double>::max() - min_t_value) < EPS) {
        return false;
    }

    intersect.point = ray(min_t_value);
    intersect.distance = min_t_value;
    intersect.normal = trIntersect->getNormal(ray);

    return true;
}