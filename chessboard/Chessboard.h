#pragma once

#include "Model.h"

class Chessboard : public Model
{
private:
    std::shared_ptr<Model> black_cells;
    std::shared_ptr<Model> white_cells; 
    std::shared_ptr<Model> base;

public:
    Chessboard(std::shared_ptr<Model> _black_cells, 
                std::shared_ptr<Model> _white_cells, 
                std::shared_ptr<Model> _base);

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const;
    virtual void transform(const std::shared_ptr<TransformAction> action);
    virtual Point3 getCenter() noexcept;

    virtual size_t getCountFaces() const noexcept;
    virtual std::ostream& print(std::ostream &os) const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Chessboard &model);
