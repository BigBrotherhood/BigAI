#include <../inc/dataset.hpp>

data::data(std::string line) {

    std::cout << line << std::endl;
}

data::~data() {

    
}

dataset::dataset(std::fstream stream) {

    std::string line;

    if (stream.good()) {
        while(!stream.eof()) {
            std::getline(stream, line);
            _set[line.substr(0, line.find(','))] = new data(line);
        }
    }
}

dataset::~dataset() {

    _set.clear();
}