#include "DataChessboardReader.h"

DataChessboardReader::DataChessboardReader(const char *fname)
: Reader(fname) {}

void DataChessboardReader::readData() {
    assert(isOpen());
    file.seekg(0, std::ios::beg);   // переместить курсор на начало файла

    int count_data_read = 0;
    std::string type;
    while (!file.eof()) {
        file >> type;
        if (!file) {
            if (printing)
                std::cout << "end of file;\n";
            continue;
        }
        if (type == "r_chess") {
            file >> r_chess;
            if (!file) {
                time_t curTime = time(NULL);
                throw FloatReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
            }
            ++count_data_read;
        } else if (type == "delta_r") {
            file >> delta_r;
            if (!file) {
                time_t curTime = time(NULL);
                throw FloatReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
            }
            ++count_data_read;
        } else {
            if (printing)
                std::cout << "symbol: |" << type << "|\n";
            time_t curTime = time(NULL);
            throw SymbolReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
    }

    if (count_data_read != 2) {
        time_t curTime = time(NULL);
        throw DataNotFullReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
}

Point3 DataChessboardReader::getCenterOfCell00() {
    double wcell = (r_chess + delta_r) * 2;
    double x, z;
    x = wcell / 2 - wcell * 4;
    z = x;
    return Point3(x, 0, z);
}