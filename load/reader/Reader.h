#pragma once

#include "Exceptions.h"
#include <fstream>
#include <assert.h>

class Reader 
{
protected:
    const char *filename;
    std::ifstream file;
public:
    Reader(const char *fname);
    virtual ~Reader();

    virtual void open();
    virtual void close();
    virtual bool isOpen();

    virtual void readData() = 0;
};
