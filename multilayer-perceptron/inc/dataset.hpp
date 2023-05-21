#pragma once

# include <map>
# include <fstream>
# include <iostream>
# include <vector>
# include "fixed.hpp"

class data {

private:

    std::map<std::string, double> _mean;
    std::map<std::string, double> _error;
    std::map<std::string, double> _worst;
    std::vector<std::string>      _features;
    bool                          diagnosis;

public:

    data(std::string);
    double get_mean(std::string);
    bool get_diagnosis() { return diagnosis; }
    double get_error(std::string);
    double get_worst(std::string);
    void insert_features(int, double);
    void init_features();
    ~data();
};

class dataset {

private:

    std::map<std::string, data *> _set;

public:

    dataset(std::string);
    ~dataset();

};