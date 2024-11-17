#include "Chessboard.h"


Chessboard::Chessboard(std::shared_ptr<Model> _black_cells, 
                        std::shared_ptr<Model> _white_cells, 
                        std::shared_ptr<Model> _base,
                        double cell_width) {
    black_cells = _black_cells;
    white_cells = _white_cells;
    base = _base;

    double cw2 = cell_width / 2; // 16
    double x0, z0;
    x0 = - 4 * cell_width + cw2;
    z0 = 4 * cell_width - cw2;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            posCells[i][j] = Point3(x0 + cell_width * i, 0, z0 - cell_width * j);
        }
    
    // std::cout << "Chessboard \n";
    // std::cout << "cw = " << cell_width << "\n";
    // std::cout << posCells[0][0] << " " << posCells[0][1] << "\n\n\n";
}

bool Chessboard::isComposite() const { return true; }

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
            iout = iwhite;
            find = true;
        }
    }
    
    if (find) {
        intersect = iout;
    }
    return find;
}

void Chessboard::transform(const std::shared_ptr<TransformAction> action) {
    (void) action;
}

Point3 Chessboard::getCenter() noexcept {
    return Point3(0, 0, 0);
}

Point3 Chessboard::getPosCell(size_t i, size_t j) const {
    if (i >= 8 || j >= 8) {
        time_t curTime = time(NULL);
        throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return posCells[i][j];
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
