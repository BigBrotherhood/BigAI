#pragma once

# include <map>
# include <fstream>
# include <iostream>
# include <vector>
# include "fixed.hpp"

class data {

private:

    std::map<std::string, double> _mean;
    std::vector<std::string> _features;
    std::map<std::string, double> _error;
    std::map<std::string, double> _worst;
    bool                         diagnosis;

public:

    data(std::string);
    double get_mean(std::string);
    bool get_diagnosis() { return diagnosis; }
    double get_error(std::string);
    double get_worst(std::string);
    // std::vector<std::string> get_features() { return _features; }
    void insert_features(int features, double number);
    void init_features();
    ~data();
};

class dataset {

private:

    std::map<std::string, data *> _set;

public:

    dataset(std::string path);
    ~dataset();

};