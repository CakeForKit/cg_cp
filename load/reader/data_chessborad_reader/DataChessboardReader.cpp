#include "DataChessboardReader.h"

DataChessboardReader::DataChessboardReader(const char *fname)
: Reader(fname) {}

void DataChessboardReader::readData() {
    assert(isOpen());
    file.seekg(0, std::ios::beg);   // переместить курсор на начало файла

    std::cout << "DataChessboardReader::readData:\n";
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
            std::cout << "r_chess = " << r_chess << "\n";
            if (!file) {
                time_t curTime = time(NULL);
                throw FloatReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
            }
            ++count_data_read;
        } else if (type == "delta_r") {
            file >> delta_r;
            std::cout << "delta_r = " << delta_r << "\n";
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
    dataRead = true;
}

double DataChessboardReader::getCellWidth() {
    if (!dataRead) {
        time_t curTime = time(NULL);
        throw DataNotReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
    return (r_chess + delta_r) * 2;
}