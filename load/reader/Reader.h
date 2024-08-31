#pragma once

class Reader 
{
public:
    virtual ~Reader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;

    virtual bool isOpen() = 0;
};
