#include "../inc/dataset.hpp"

dataset::dataset() {

    std::string     line;
    std::fstream    stream;

    stream.open("data/data.csv");
    if (stream.good()) {
        while(!stream.eof()) {
            std::getline(stream, line);
            // _set[line.substr(0, line.find(','))] = new data(line);
            line.clear();
        }
        stream.close();
    } else { std::cout << "An error occured while opening the database" << std::endl; }
}

dataset::~dataset() {

}