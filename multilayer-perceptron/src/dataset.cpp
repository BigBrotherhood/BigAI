#include "../inc/dataset.hpp"
# include <sstream>
# include <string>
# include <charconv>

void data::init_features() {

    std::fstream feats("data/features.txt");
    std::string str;
    while (!feats.eof()) {
        std::getline(feats, str);
        _features.push_back(str);
    }
}


void print_map(std::map<std::string, double> map) {
    for (auto it = map.begin(); it != map.end(); it++)
        std::cout << it->first << " => " << it->second << std::endl;
}


data::data(std::string line) {

    std::stringstream ss(line);
    std::string token;
    int count = 0;
    init_features();
    while (!ss.eof()) {
        std::getline(ss, token, ',');
        if (count >= 2) { // Ignore the first two tokens
            try { insert_features(count - 2, stod(token)); } 
            catch (std::exception) {}
        }
        count++;
    }
}


void data::insert_features(int features, double number) {

    if (features < 10)
        _mean.insert(std::make_pair(_features.at(features), number));
    else if (features > 10 && features < 20)
        _error.insert(std::make_pair(_features.at(features), number));
    else
        _worst.insert(std::make_pair(_features.at(features), number));

}

double data::get_mean(std::string feature) {

    return _mean[feature];
}

double data::get_error(std::string feature) {

    return _error[feature];
}

double data::get_worst(std::string feature) {

    return _worst[feature];
}

data::~data() {}

dataset::dataset(std::string path) {

    std::string     line;
    std::fstream    stream;

    stream.open(path);
    if (stream.good()) {
        while(stream.eof() == false) {
            std::getline(stream, line);
            if (!line.empty())
                _set.insert(std::make_pair(line.substr(0, line.find(',')), new data(line)));
        }
    } else { std::cout << "An error occured while opening the database" << std::endl; }
    std::cout << "id: 92751 == " << _set["92751"]->get_mean("Mean radius") << std::endl;
}

dataset::~dataset() {
    _set.clear();
}