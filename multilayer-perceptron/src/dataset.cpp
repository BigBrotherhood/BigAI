#include "../inc/dataset.hpp"
# include <sstream>

dataset::dataset() {

    int id = 0;
    std::string     line, token;
    std::stringstream    stream("data/data.csv");

    // stream.open("data/data.csv");
    if (stream.good()) {
        while(!stream.eof()) {
            std::getline(stream, line);
            while (std::getline(stream, token, ',')) {
                _set[id][0] = token == "M" ? 1 : 0;
                for (int i = 1; i < 31; i++) {
                    std::getline(stream, token, ',');
                    _set[id][i] = std::stod(token);
                }
            }
            line.clear();
            id++;
        }
    } else { std::cout << "An error occured while opening the database" << std::endl; }
}

dataset::~dataset() {

}