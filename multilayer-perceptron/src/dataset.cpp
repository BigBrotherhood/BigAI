#include "../inc/dataset.hpp"

data::data(std::string line) {

    std::cout << line << std::endl;
    std::string diag = line.substr(line.find(','), line.find(','));
    
    _mean["diagnosis"] = fixed(diag[0] - 'B');
    std::cout <<  "|| " << _mean["diagnosis"] << " ||" << std::endl;
}

data::~data() {

    
}

dataset::dataset(std::string path) {

    std::string     line;
    std::fstream    stream;

    stream.open(path);
    if (stream.good()) {
        while(!stream.eof()) {
            std::getline(stream, line);
            _set[line.substr(0, line.find(','))] = new data(line);
        }
    } else { std::cout << "An error occured while opening the database" << std::endl; }
}

dataset::~dataset() {

    _set.clear();
}