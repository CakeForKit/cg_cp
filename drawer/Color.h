#pragma once

#include <QColor>

class Color : public QColor
{
public:
    Color(int r, int g, int b);

    const QColor getQColor() const;
};
