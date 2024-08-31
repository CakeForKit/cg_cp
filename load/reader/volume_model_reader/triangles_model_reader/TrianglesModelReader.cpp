#include "TrianglesModelReader.h"



TrianglesModelReader::TrianglesModelReader(const char *fname) 
: filename(fname), 
vertices(std::vector<psPoint3>()), triangles(std::vector<std::vector<psPoint3>>()), center(Point3()) {}

TrianglesModelReader::~TrianglesModelReader() {
    if (isOpen()) {
        close();
    }
}

void TrianglesModelReader::open() {
    if (isOpen()) {
        return;
    }
    file.open(filename);
    if (!file) {
        time_t curTime = time(NULL);
        throw NoFileReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }
}

void TrianglesModelReader::close() {
    if (!isOpen())
        return;
    file.close();
}

bool TrianglesModelReader::isOpen() { return file.is_open(); }

void TrianglesModelReader::readVectex() {
    float x, y, z;
    file >> x >> y >> z;
    if (!file) {
        time_t curTime = time(NULL);
        throw FloatReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    vertices.push_back(std::make_shared<Point3>(x, y, z));
    std::cout << Point3(x, y, z) << '\n';
}

void TrianglesModelReader::readTriangle() {
    char ch;
    int ind;
    std::vector<size_t> indexes;

    for (size_t i = 0; i < 3; ++i) {
        file >> ch;
        if (!file) {
            time_t curTime = time(NULL);
            throw EndReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
        bool symblor_error = true;
        if (ch == 'v') {
            file >> ind;
            if (file) {
                symblor_error = false;

                if (ind <= 0 || static_cast<size_t>(ind) > vertices.size()) {
                    time_t curTime = time(NULL);
                    throw IndexException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
                }
                indexes.push_back(static_cast<size_t>(ind - 1));
            }
        }
        if (symblor_error) {
            std::cout << "ch = |" << ch << "|\n";
            time_t curTime = time(NULL);
            throw SymbolReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
    }

    std::cout << *(vertices[indexes[0]]) << " " << *(vertices[indexes[1]]) << " " << *(vertices[indexes[2]]) << "\n";
    triangles.push_back({vertices[indexes[0]], vertices[indexes[1]], vertices[indexes[2]]});
}

void TrianglesModelReader::readData() {
    assert(isOpen());
    file.seekg(0, std::ios::beg);   // переместить курсор на начало файла

    std::string type;
    while (!file.eof()) {
        file >> type;
        if (!file) {
            std::cout << "!!!\n";
            continue;
        }
        if (type == "v") {
            readVectex();

        } else if (type == "f") {
            readTriangle();

        } else if (type == "c") {
            float x, y, z;
            file >> x >> y >> z;
            if (!file) {
                time_t curTime = time(NULL);
                throw FloatReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
            }
            center = Point3(x, y, z);
            std::cout << "center = " << center << "\n";

        } else if (type[0] == '#' || type == "\n" || type == "") {
            std::getline(file, type);
            std::cout << "----\n";

        } else {
            std::cout << "symbol: |" << type << "|\n";
            time_t curTime = time(NULL);
            throw SymbolReadException(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
    }
    
}

std::vector<std::vector<psPoint3>> TrianglesModelReader::getFaces() {
    return triangles;
}

Point3 TrianglesModelReader::getCenter() {
    return center;
}
