#pragma once

#include "ReaderCreator.h"

class ReaderCreatorMaker
{
public:
    template <Derivative<Reader> TReader, typename... Args>
    requires NotAbstract<TReader> && Constructible<TReader, Args...>
    static std::shared_ptr<ReaderCreator> createReaderCreator() {
        return std::make_shared<TemplateReaderCreator<TReader, Args...>>();
    }
};