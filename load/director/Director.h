#pragma once

#include "Model.h"

class Director
{
public:
    virtual ~Director() = 0;

    virtual std::shared_ptr<Model> get() = 0;

protected:
    virtual void create() = 0;
};
