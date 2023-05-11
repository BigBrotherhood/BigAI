#include "../inc/dataset.hpp"
# include <sstream>
# include <string>
# include <charconv>

void print_vector(std::vector<std::string> vec) {
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << std::endl;
}
void data::init_features() {

    std::fstream feats("data/features.txt");
    std::string str, tmp;
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
            try {
                // std::cout << "token: " << token << std::endl;
                insert_features(count - 2, stod(token));
            } catch (std::exception) {
                // std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        count++;
    }
    print_map(_mean);
    // std::cout << "mead peri: " << _mean["Mean perimeter"] << std::endl;
    // std::cout << "stand error of area: " << _error["Standard error of area"] << std::endl;
    // std::cout << " worst smoothness: " << _worst["Worst smoothness"] << std::endl;
    
}


void data::insert_features(int features, double number) {

    // std::cout << "features: " << features << std::endl;
    // std::cout << "number: " << number << std::endl;
    if (features < 10) {
        _mean.insert(std::make_pair(_features.at(features), number));
        // std::cout << _ << _mean[_features.at(features)] << std::endl;
        

    }
    else if (features > 10 && features < 20) {
        _error.insert(std::make_pair(_features.at(features), number));
        // std::cout << "error: " << _error[_features.at(features)] << std::endl;
    }
    else {
        _worst.insert(std::make_pair(_features.at(features), number));
        // std::cout << "worst: " << _worst[_features.at(features)] << std::endl;
    }

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

data::~data() {

    
}

dataset::dataset(std::string path) {

    std::string     line;
    std::fstream    stream;

    stream.open(path);
    if (stream.good()) {
        while(stream.eof() == false) {
            std::getline(stream, line);
            if (!line.empty())
                _set[line.substr(0, line.find(','))] = new data(line);
        }
    } else { std::cout << "An error occured while opening the database" << std::endl; }
    std::cout << "id: 926125 == " << _set["92751"]->get_error("Mean radius") << std::endl;
}

dataset::~dataset() {

    _set.clear();
}