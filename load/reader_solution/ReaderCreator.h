#pragma once

#include "VolumeModelReader.h"
#include "concepts.h"

class ReaderCreator
{
public:
    virtual ~ReaderCreator() = default;
    // virtual std::shared_ptr<Reader> createReader() const = 0;
};


template <Derivative<Reader> TReader, typename... Args>
requires NotAbstract<TReader> && Constructible<TReader, Args...>
class TemplateReaderCreator : public ReaderCreator
{
public:
    std::shared_ptr<Reader> createReader(Args&&... args) const override {
        return std::make_shared<TReader>(args...);
    }
};