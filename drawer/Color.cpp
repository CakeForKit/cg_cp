#include "Color.h"

Color::Color(int r, int g, int b) {
    this->setRgb(r, g, b);
}

const QColor Color::getQColor() const {
    return QColor(rgb());
}