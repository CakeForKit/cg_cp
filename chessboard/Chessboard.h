#pragma once

#include "Model.h"

class Chessboard : public Model
{
private:
    std::shared_ptr<Model> black_cells;
    std::shared_ptr<Model> white_cells; 
    std::shared_ptr<Model> base;
    Point3 posCells[8][8];

public:
    Chessboard(std::shared_ptr<Model> _black_cells, 
                std::shared_ptr<Model> _white_cells, 
                std::shared_ptr<Model> _base,
                double cell_width);

    virtual bool isComposite() const;

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const override;
    virtual void transform(const std::shared_ptr<TransformAction> action) override;
    virtual Point3 getCenter() noexcept override;
    Point3 getPosCell(size_t i, size_t j) const;

    virtual size_t getCountFaces() const noexcept override;
    virtual std::ostream& print(std::ostream &os) const noexcept override;
};

std::ostream& operator<<(std::ostream &os, const Chessboard &model);
