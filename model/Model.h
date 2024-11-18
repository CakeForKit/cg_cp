#pragma once

#include <memory>
#include <vector>
#include <map>
#include "intersection_type.h"
#include "Ray.h"
#include "TransformAction.h"

enum class typeChess {
    PAWN,
    ROOK
};

static std::map<const typeChess, const char *> mapNamesChess = {
    {typeChess::PAWN, "Пешка"},
    {typeChess::ROOK, "Ладья"}
};

class Model;

using PtrModel = std::shared_ptr<Model>;
using VectorPtrModel = std::vector<PtrModel>;

class Model
{
protected:
    typeChess type;

public:
    using value_type = Model;
    using size_type = size_t;
    using iterator = VectorPtrModel::const_iterator;
    using const_iterator = VectorPtrModel::const_iterator;

    virtual ~Model() = default;
    virtual bool isComposite() const = 0;
    // virtual bool add(std::initializer_list<PtrModel> comp);
    // virtual bool remove(const iterator& it);
    // virtual iterator begin() const;
    // virtual iterator end() const;

    virtual bool intersection(const Ray &ray, intersection_t &intersect) const = 0;
    virtual void transform(const std::shared_ptr<TransformAction> action) = 0;
    virtual Point3 getCenter() noexcept = 0;
    virtual Color getColor() const = 0;

    virtual size_t getCountFaces() const noexcept = 0;
    virtual std::ostream& print(std::ostream &os) const noexcept = 0;

    void setTypeChess(typeChess t) noexcept;
    typeChess getTypeChess() const noexcept;
};

std::ostream& operator<<(std::ostream &os, const Model &model);