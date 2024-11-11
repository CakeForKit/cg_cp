#include "Chessboard.h"


Chessboard::Chessboard(std::shared_ptr<Model> _black_cells, 
                        std::shared_ptr<Model> _white_cells, 
                        std::shared_ptr<Model> _base) {
    black_cells = _black_cells;
    white_cells = _white_cells;
    base = _base;
}

bool Chessboard::intersection(const Ray &ray, intersection_t &intersect) const {
    intersection_t ibase, iblack, iwhite, iout; 
    bool find = false;
    if (base->intersection(ray, ibase)) {
        iout = ibase;
        find = true;
    }
    if (black_cells->intersection(ray, iblack)) {
        if (!find || (find && iblack.distance < iout.distance)) {
            iout = iblack;
            find = true;
        }
    }
    if (white_cells->intersection(ray, iwhite)) {
        if (!find || (find && iwhite.distance < iout.distance)) {
            iout = iblack;
            find = true;
        }
    }
    
    if (find) {
        intersect = iout;
        std::cout << intersect << "\n";
    }
    return find;
}

void Chessboard::transform(const std::shared_ptr<TransformAction> action) {
    (void) action;
}

Point3 Chessboard::getCenter() noexcept {
    return Point3(0, 0, 0);
}

size_t Chessboard::getCountFaces() const noexcept {
    return base->getCountFaces() + black_cells->getCountFaces() + white_cells->getCountFaces();
}

std::ostream& Chessboard::print(std::ostream &os) const noexcept {
    os << "base-chessboard" << *base << '\n';
    os << "black_cells-chessboard" << *black_cells << '\n';
    os << "white_cells-chessboard" << *white_cells << '\n';
    return os;
}

std::ostream& operator<<(std::ostream &os, const Chessboard &model) {
    return model.print(os);
}
