#pragma once

#include "ObjectScene.h"

class CompositeObjectScene: public Model
{
private:
    VectorPtrModel vec;
public:
    CompositeObjectScene() = default;
    CompositeObjectScene(PtrModel first, ...);

    bool isComposite() const override;
    bool add(std::initializer_list<PtrModel> list) override;
    bool remove(const iterator& it) override;
    iterator begin() const override;
    iterator end() const override;
};