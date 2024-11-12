#include "Reader.h"


Reader::Reader(const char *fname)
: filename(fname) {}

Reader::~Reader() {
    if (isOpen()) {
        close();
    }
}

void Reader::open() {
    if (isOpen()) {
        return;
    }
    file.open(filename);
    if (!file) {
        time_t curTime = time(NULL);
        throw NoFileReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
}

void Reader::close() {
    if (!isOpen())
        return;
    file.close();
}

bool Reader::isOpen() { return file.is_open(); }